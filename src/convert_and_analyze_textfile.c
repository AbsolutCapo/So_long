/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_and_analyze_textfile.c                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 17:06:52 by cpost         #+#    #+#                 */
/*   Updated: 2022/07/01 14:45:21 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"
#include "ft_printf.h"
#include "libft.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

/**
 * Child function of split_text_to_array.
 * 
 * @param[in] fd file descriptor
 * @param[in] total_string the entire map in 1 string
 * @return the 2d array of the map
 */
static char	**create_final_map(int fd, char *total_string)
{
	char	**map;

	close(fd);
	check_for_double_newlines(total_string);
	map = ft_split(total_string, '\n');
	if (total_string)
		free(total_string);
	return (map);
}

/**
 * Joins two strings and free's the origin string (total_str)
 * 
 * @param[in] total_str the origin string
 * @param[in] line_read the string that has to be appended to total_string
 * @return pointer to the joined string
 */
static char	*ft_strjoin_free(char *s1, char *s2)
{
	unsigned int	size_s1;
	unsigned int	size_s2;
	char			*str;

	if (!s2 && !s1)
		return (0);
	if (!s1 && s2)
		return (ft_strdup(s2));
	size_s1 = ft_strlen((char *)s1);
	size_s2 = ft_strlen((char *)s2);
	str = malloc((size_s1 + size_s2 + 1) * sizeof(char));
	if (!str)
	{
		free(s1);
		return (NULL);
	}
	ft_memcpy(str, s1, size_s1);
	ft_memcpy(str + size_s1, s2, size_s2);
	str[size_s1 + size_s2] = 0;
	free(s1);
	return (str);
}

/**
 * Takes the map (as a .ber file) and splits it into a 2d array. This function
 * first puts the .ber file into one long array with get_next_line. Then
 * ft_split is used to split this array into a 2d array.
 * @param[in] filename the path to the .ber file
 * @return a pointer to a 2d array which contains the map of the game
 */
char	**split_text_file_to_array(char *filename, char *total_string)
{
	int		fd;
	char	*line_read;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	line_read = get_next_line(fd);
	if (!line_read)
		close(fd);
	if (!line_read)
		return (NULL);
	while (line_read)
	{
		total_string = ft_strjoin_free(total_string, line_read);
		if (!total_string)
		{
			close(fd);
			free(line_read);
			return (NULL);
		}
		free(line_read);
		line_read = get_next_line(fd);
	}
	return (create_final_map(fd, total_string));
}

/**
 * Gets the starting position of the player in the map and stores it's x and y
 * values inside of the game struct.
 * 
 * @param[in] map the map of the game
 * @param[in] game The overall struct with all the game information in it
 * 
 * @return Nothing
 */
static void	store_player_and_exit_position(char **map, t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				game->mapinfo.player_x = x;
				game->mapinfo.player_y = y;
			}
			if (map[y][x] == 'E')
			{
				game->mapinfo.exit_x = x;
				game->mapinfo.exit_y = y;
			}
			x++;
		}
		y++;
	}
}

/**
 * Count the amount of P, C, E and rows in the map. Also determines the
 * length of the first/upper row. This information is set in the 'game'
 * struct
 * 
 * @param[in] map the map of the game
 * @param[in] game The overall game struct with all the information in it
 * 
 * @return Nothing
 */
void	get_map_info(char **map, t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				game->mapinfo.number_of_players++;
			if (map[y][x] == 'C')
				game->mapinfo.number_of_collectibles++;
			if (map[y][x] == 'E')
				game->mapinfo.number_of_exits++;
			if (y == 0)
				game->mapinfo.length_of_first_row++;
			x++;
		}
		y++;
		game->mapinfo.number_of_rows++;
	}
	set_window_definitions(game);
	store_player_and_exit_position(map, game);
}
