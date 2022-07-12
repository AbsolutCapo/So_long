/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move_enemy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/18 17:41:34 by cpost         #+#    #+#                 */
/*   Updated: 2022/06/23 13:33:00 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "MLX42/MLX42.h"

/**
 * Child function of update_enemy
 * @param[in] all struct containing mlx, map, and game
 * @param[in] x position of the enemy on x-axis
 * @param[in] y position of the enemy on y-axis
 * @return none
 * hasn't moved.
 */
static void	update_enemy_move(t_all *all, char direction, unsigned int x,
			unsigned int y)
{
	if (direction == 'D')
	{
		all->map2[y][x] = '0';
		all->map2[y][x + 1] = 'X';
		all->game->mapinfo.enemy_x += 1;
	}
	if (direction == 'W')
	{
		all->map2[y][x] = '0';
		all->map2[y - 1][x] = 'X';
		all->game->mapinfo.enemy_y -= 1;
	}
	if (direction == 'S')
	{
		all->map2[y][x] = '0';
		all->map2[y + 1][x] = 'X';
		all->game->mapinfo.enemy_y += 1;
	}
	if (direction == 'A')
	{
		all->map2[y][x] = '0';
		all->map2[y][x - 1] = 'X';
		all->game->mapinfo.enemy_x -= 1;
	}
}

/**
 * Moves enemy 1 position
 * @param[in] all struct containing mlx, map, and game
 * @param[in] x position of the enemy on x-axis
 * @param[in] y position of the enemy on y-axis
 * @return none
 * hasn't moved.
 */
void	update_enemy(t_all *all, unsigned int x, unsigned int y)
{
	if ((y == 5 && x == 6) || (y == 5 && x == 5))
	{
		if (all->map[y][x + 1] != '1')
			update_enemy_move(all, 'D', x, y);
	}
	else if ((y == 5 && x == 7) || (y == 4 && x == 7))
	{
		if (all->map[y - 1][x] != '1')
			update_enemy_move(all, 'W', x, y);
	}
	else if ((y == 3 && x == 5) || (y == 4 && x == 5))
	{
		if (all->map[y + 1][x] != '1')
			update_enemy_move(all, 'S', x, y);
	}
	else if ((y == 3 && x == 7) || (y == 3 && x == 6))
	{
		if (all->map[y][x - 1] != '1')
			update_enemy_move(all, 'A', x, y);
	}
	mlx_delete_image(all->mlx, all->game->images.enemy_img);
	all->game->images.enemy_img = mlx_new_image(all->mlx,
			all->game->mapinfo.win_width, all->game->mapinfo.win_height);
	draw_enemy(all);
}
