/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   valid_map_check.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/11 14:54:32 by cpost         #+#    #+#                 */
/*   Updated: 2022/06/27 18:47:49 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_printf.h"

/**
 * Checks if 'amount of players is 1', 'amount of exits is 1', 'amount of
 * collectibles is at least 1'.
 * 
 * @param[in] map the map of the game
 * @param[in] game The overall game struct with all the information in it
 * 
 * @return 1 if error is found, 0 if no error is found
 */
static int	check_valid_exits_players_collectibles(t_game *game)
{
	if (game->mapinfo.number_of_players != 1)
	{
		ft_printf("There must be 1 (and only 1) player in the map\n");
		return (1);
	}
	if (game->mapinfo.number_of_exits != 1)
	{
		ft_printf("There must be 1 (and only 1) exit in the map\n");
		return (1);
	}
	if (game->mapinfo.number_of_collectibles == 0)
	{
		ft_printf("There must be at least 1 collectible in the map\n");
		return (1);
	}
	return (0);
}

/**
 * Tests if all the rows contain the same amount of characters as the first row.
 * 
 * @param[in] map the map of the game
 * @param[in] game The overall game struct with all the information in it
 * 
 * @return 1 if error is found, 0 if no error is found
 */
static int	check_valid_row_length(char **map, t_game *game)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	y = 0;
	while (map[y])
	{
		while (map[y][x])
			x++;
		if (x != game->mapinfo.length_of_first_row)
		{
			ft_printf("Amount of characters on all rows must be equal\n");
			return (1);
		}
		y++;
		x = 0;
	}
	return (0);
}

/**
 * Checks if the borders are all 1's
 * 
 * @param[in] map the map of the game
 * @param[in] game The overall game struct with all the information in it
 * 
 * @return 1 if error is found, 0 if no error is found
 */
static int	check_valid_borders(char **map, t_game *game)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	y = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if ((map[y][x] != '1') && (y == 0 || x == 0
			|| y == game->mapinfo.number_of_rows - 1
			|| x == game->mapinfo.length_of_first_row - 1))
			{
				ft_printf("The borders of the map must be only 1's\n");
				return (1);
			}
			x++;
		}
		y++;
		x = 0;
	}
	return (0);
}

/**
 * Checks if the map only contains: 1, 0, C, E & P
 * 
 * @param[in] map the map of the game
 * @param[in] game The overall game struct with all the information in it
 * 
 * @return 1 if error is found, 0 if no error is found
 */
static int	check_valid_characters(char **map)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	y = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (!((map[y][x] == '1') || (map[y][x] == '0')
			|| (map[y][x] == 'C') || (map[y][x] == 'E')
			|| (map[y][x] == 'P')))
			{
				ft_printf("Only 1, 0, C, E & P are allowed in the map\n");
				return (1);
			}
			x++;
		}
		y++;
		x = 0;
	}
	return (0);
}

/**
 * In this function we do a number of checks to make sure that the
 * map we provided is valid.
 * 
 * @param[in] map the inputted map
 * @param[in] game The overall game struct with all the information in it
 * 
 * @return 1 if error is found in the map, 0 if no error is found in the map
 */
int	check_for_invalid_map(char **map, t_game *game)
{
	if (check_valid_characters(map))
		return (1);
	if (check_valid_exits_players_collectibles(game))
		return (1);
	if (check_valid_row_length(map, game))
		return (1);
	if (check_valid_borders(map, game))
		return (1);
	return (0);
}
