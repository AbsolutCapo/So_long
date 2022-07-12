/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/29 11:28:46 by cpost         #+#    #+#                 */
/*   Updated: 2022/06/23 13:11:53 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_printf.h"
#include "MLX42/MLX42.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Starts a new function (move_player) that moves the player. If the move was 
 * succesful then the amount of moves is printed on the standard output.
 * @param[in] direction the direction the player wants to move in
 * @return Nothing
 */
static void	print_and_move(char direction, t_all *all)
{
	if (check_valid_move(direction, all, all->game->mapinfo.player_x,
			all->game->mapinfo.player_y))
	{
		check_enemy(all, all->game->mapinfo.player_x,
			all->game->mapinfo.player_y);
		all->game->mapinfo.moves++;
		ft_printf("%d\n", all->game->mapinfo.moves);
		check_collectibles(all, all->game->mapinfo.player_x,
			all->game->mapinfo.player_y, direction);
		move_player(all, all->game->mapinfo.player_x,
			all->game->mapinfo.player_y, direction);
		update_counter(all);
		check_enemy(all, all->game->mapinfo.player_x,
			all->game->mapinfo.player_y);
		if (all->game->mapinfo.moves % 2 == 0
			&& all->game->mapinfo.enemy_x != 0)
			update_enemy(all, all->game->mapinfo.enemy_x,
				all->game->mapinfo.enemy_y);
		update_light(all);
		check_exit(all, all->game->mapinfo.player_x,
			all->game->mapinfo.player_y);
		check_enemy(all, all->game->mapinfo.player_x,
			all->game->mapinfo.player_y);
	}
}

/**
 * Executes action if a key is pressed.
 * @param[in] keydata the value of the key pressed.
 * @param[in] param a parameter of own choice.
 * @return Nothing
 */
void	execute_hook(mlx_key_data_t keydata, void *param)
{
	t_all	*all;

	all = param;
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if (keydata.key == MLX_KEY_ESCAPE || keydata.key == MLX_KEY_Q)
			free_all_and_exit(all, EXIT_FAILURE);
		if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
			print_and_move('W', all);
		if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
			print_and_move('A', all);
		if (keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
			print_and_move('S', all);
		if (keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
			print_and_move('D', all);
	}
}
