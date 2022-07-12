/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_exit_or_enemy.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/17 12:06:40 by cpost         #+#    #+#                 */
/*   Updated: 2022/05/30 11:55:57 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "MLX42/MLX42.h"
#include <stdlib.h>
#include "ft_printf.h"

/**
 * Checks if the player hits the enemy.
 * @param[in] all struct containing mlx, map, and game
 * @param[in] x position of the player on x-axis
 * @param[in] y position of the player on y-axis
 * @return nothing
 */
void	check_enemy(t_all *all, unsigned int x,
			unsigned int y)
{
	if ((x == all->game->mapinfo.enemy_x) && (y == all->game->mapinfo.enemy_y))
		free_all_and_exit(all, EXIT_SUCCESS);
}

/**
 * Checks if the player over the exit and if there are no collectibles left.
 * If condition is true, exit game.
 * @param[in] all struct containing mlx, map, and game
 * @param[in] x position of the player on x-axis
 * @param[in] y position of the player on y-axis
 * @return nothing
 */
void	check_exit(t_all *all, unsigned int x,
			unsigned int y)
{
	if ((x == all->game->mapinfo.exit_x) && (y == all->game->mapinfo.exit_y)
		&& (all->game->mapinfo.number_of_collectibles == 0))
		free_all_and_exit(all, EXIT_SUCCESS);
}
