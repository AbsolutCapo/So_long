/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/20 17:25:08 by cpost         #+#    #+#                 */
/*   Updated: 2022/05/30 15:35:58 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "MLX42/MLX42.h"
#include <stdlib.h>
#include "ft_printf.h"

static void	free_images(t_all *all)
{
	if (all->game->images.background_img)
		mlx_delete_image(all->mlx, all->game->images.background_img);
	if (all->game->images.collectible_img)
		mlx_delete_image(all->mlx, all->game->images.collectible_img);
	if (all->game->images.counter_img)
		mlx_delete_image(all->mlx, all->game->images.counter_img);
	if (all->game->images.enemy_img)
		mlx_delete_image(all->mlx, all->game->images.enemy_img);
	if (all->game->images.exit_img)
		mlx_delete_image(all->mlx, all->game->images.exit_img);
	if (all->game->images.light_img)
		mlx_delete_image(all->mlx, all->game->images.light_img);
	if (all->game->images.player_img)
		mlx_delete_image(all->mlx, all->game->images.player_img);
}

static void	free_game(t_all *all)
{
	if (all->game->textures.collectible)
		mlx_delete_texture(all->game->textures.collectible);
	if (all->game->textures.enemy)
		mlx_delete_texture(all->game->textures.enemy);
	if (all->game->textures.exit)
		mlx_delete_texture(all->game->textures.exit);
	if (all->game->textures.ground)
		mlx_delete_texture(all->game->textures.ground);
	if (all->game->textures.light)
		mlx_delete_texture(all->game->textures.light);
	if (all->game->textures.player)
		mlx_delete_texture(all->game->textures.player);
	if (all->game->textures.wall)
		mlx_delete_texture(all->game->textures.wall);
	free_images(all);
	free(all->game);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (map)
	{
		while (map[i])
		{
			if (map[i])
				free(map[i]);
			i++;
		}
		free(map);
	}
}

void	free_all_and_exit(t_all *all, int exit_code)
{
	if (all->map)
		free_map(all->map);
	if (all->map2)
		free_map(all->map2);
	if (all->game)
		free_game(all);
	if (all->mlx)
		mlx_terminate(all->mlx);
	if (all)
		free(all);
	exit(exit_code);
}
