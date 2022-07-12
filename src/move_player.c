/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move_player.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/16 12:51:10 by cpost         #+#    #+#                 */
/*   Updated: 2022/05/25 14:14:01 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "MLX42/MLX42.h"

/**
 * Moves player 1 position
 * @param[in] all struct containing mlx, map, and game
 * @param[in] x position of the player on x-axis
 * @param[in] y position of the player on y-axis
 * @param[in] direction the direction the player will move in
 * @return 1 if player has moved. 0 if the move was not valid, and player 
 * hasn't moved.
 */
void	move_player(t_all *all, unsigned int x, unsigned int y,
				char direction)
{
	all->map[y][x] = '0';
	if (direction == 'W')
	{
		all->map[y - 1][x] = 'P';
		all->game->mapinfo.player_y -= 1;
	}
	if (direction == 'A')
	{
		all->map[y][x - 1] = 'P';
		all->game->mapinfo.player_x -= 1;
	}
	if (direction == 'S')
	{
		all->map[y + 1][x] = 'P';
		all->game->mapinfo.player_y += 1;
	}
	if (direction == 'D')
	{
		all->map[y][x + 1] = 'P';
		all->game->mapinfo.player_x += 1;
	}
	mlx_delete_image(all->mlx, all->game->images.player_img);
	all->game->images.player_img = mlx_new_image(all->mlx,
			all->game->mapinfo.win_width, all->game->mapinfo.win_height);
	draw_player(all, all->game->images.player_img);
}

/**
 * Checks if a move is valid. If the move is valid the player is moved by
 * calling the 'move_player' function.
 * @param[in] direction the direction the player has to move in
 * @param[in] all struct containing mlx, map, and game
 * @param[in] x position of the player on x-axis
 * @param[in] y position of the player on y-axis
 * @return 1 if move is valid and executed. 0 if move is not valid
 */
int	check_valid_move(char direction, t_all *all, unsigned int x,
			unsigned int y)
{
	if ((direction == 'W') && (all->map[y - 1][x] == '1'))
		return (0);
	if ((direction == 'A') && (all->map[y][x - 1] == '1'))
		return (0);
	if ((direction == 'S') && (all->map[y + 1][x] == '1'))
		return (0);
	if ((direction == 'D') && (all->map[y][x + 1] == '1'))
		return (0);
	return (1);
}
