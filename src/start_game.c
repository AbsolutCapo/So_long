/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start_game.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/25 13:17:15 by cpost         #+#    #+#                 */
/*   Updated: 2022/06/23 14:05:12 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "so_long.h"
#include "ft_printf.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * Starts the main game loop. As long as the game is not terminated,
 * this function will keep running. The game will be terminated after
 * completion or manually terminating the game.
 * 
 * @param[in] map the map of the game
 * @param[in] game The overall game struct with all the information in it
 * 
 * @return 1 if the game is terminated succesfully (by completion or manual
 * termination), 0 if the initiation of the game failed.
 */
int32_t	start_game(t_all *all, unsigned int window_width,
			unsigned int window_height)
{
	all->mlx = mlx_init(window_width, window_height, "Random game", true);
	if (!all->mlx)
		free_all_and_exit(all, EXIT_FAILURE);
	draw_base_map(all);
	set_counter_zero(all);
	if (!set_enemy_standard(all))
	{
		if (!set_enemy(all))
			all->game->mapinfo.enemy_x = 0;
	}
	mlx_key_hook(all->mlx, &execute_hook, all);
	mlx_loop(all->mlx);
	return (EXIT_SUCCESS);
}
