/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fix_functions.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/23 11:46:09 by cpost         #+#    #+#                 */
/*   Updated: 2022/07/01 14:38:28 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "MLX42/MLX42.h"
#include <stdlib.h>
#include "ft_printf.h"

void	check_for_double_newlines(char *total_string)
{
	int	i;

	i = 0;
	while (total_string[i])
	{
		if ((total_string[i] == '\n' && total_string[i + 1] == '\n')
			|| total_string[0] == '\n')
		{
			free(total_string);
			ft_printf("\nNo \n\ndouble \n\nnewlines \n\nplz \n\n;)\n\n");
			exit (1);
		}
		i++;
	}
}

/**
 * Sets the values of the width and heigth of the window that has to be 
 * created and saves these values in the game struct.
 * 
 * @param[in] game The overall struct with all the game information in it
 * 
 * @return Nothing
 */
void	set_window_definitions(t_game *game)
{
	game->mapinfo.win_height = BLOCKSIZE * game->mapinfo.number_of_rows;
	game->mapinfo.win_width = BLOCKSIZE * game->mapinfo.length_of_first_row;
}
