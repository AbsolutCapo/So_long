/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_collectibles.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/17 12:06:40 by cpost         #+#    #+#                 */
/*   Updated: 2022/05/25 16:34:23 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "MLX42/MLX42.h"
#include <stdlib.h>

/**
 * Removes collectible from map and updates the collectible count.
 * @param[in] direction the direction the player has to move in
 * @param[in] all struct containing mlx, map, and game
 * @param[in] x position of the player on x-axis
 * @param[in] y position of the player on y-axis
 * @return nothing
 */
static void	remove_collectible(t_all *all, unsigned int x,
			unsigned int y, char direction)
{
	if (direction == 'W')
		all->map[y - 1][x] = '0';
	if (direction == 'A')
		all->map[y][x - 1] = '0';
	if (direction == 'S')
		all->map[y + 1][x] = '0';
	if (direction == 'D')
		all->map[y][x + 1] = '0';
	mlx_delete_image(all->mlx, all->game->images.collectible_img);
	all->game->images.collectible_img = mlx_new_image(all->mlx,
			all->game->mapinfo.win_width, all->game->mapinfo.win_height);
	if (!all->game->images.collectible_img)
		exit (0);
	draw_collectibles(all, all->game->images.collectible_img);
	all->game->mapinfo.number_of_collectibles--;
}

/**
 * Checks if the player moves over a collectible. If so, execute 
 * 'revove_collectible' function that removes the collectible from the map.
 * @param[in] direction the direction the player has to move in
 * @param[in] all struct containing mlx, map, and game
 * @param[in] x position of the player on x-axis
 * @param[in] y position of the player on y-axis
 * @return nothing
 */
void	check_collectibles(t_all *all, unsigned int x,
			unsigned int y, char direction)
{
	if ((direction == 'W') && (all->map[y - 1][x] != 'C'))
		return ;
	if ((direction == 'A') && (all->map[y][x - 1] != 'C'))
		return ;
	if ((direction == 'S') && (all->map[y + 1][x] != 'C'))
		return ;
	if ((direction == 'D') && (all->map[y][x + 1] != 'C'))
		return ;
	remove_collectible(all, all->game->mapinfo.player_x,
		all->game->mapinfo.player_y, direction);
}
