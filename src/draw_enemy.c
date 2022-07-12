/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_enemy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/18 11:26:43 by cpost         #+#    #+#                 */
/*   Updated: 2022/07/01 11:13:13 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "MLX42/MLX42.h"
#include "ft_printf.h"

/**
 * Draws the enemy onto the map.
 * 
 * @param[in] mlx main MLX handle. Handles important program data.
 * @param[in] map map of the game
 * @param[in] game overall game struct with all the information in it
 * @param[in] enemy_img image struct where the enemy is stored to
 * 
 * @return nothing
 */
void	draw_enemy(t_all *all)
{
	int	x;
	int	y;

	y = 0;
	while (all->map2[y])
	{
		x = 0;
		while (all->map2[y][x])
		{
			if (all->map2[y][x] == 'X')
				mlx_draw_texture(all->game->images.enemy_img,
					all->game->textures.enemy, x * BLOCKSIZE, y * BLOCKSIZE);
			x++;
		}
		y++;
	}
	mlx_image_to_window(all->mlx, all->game->images.enemy_img, 0, 0);
}

/**
 * Sets initial position of the enemy if the 'set_enemy' function failed to
 * find a starting position.
 * @param[in] all struct containing mlx, map, and game
 * @return nothing
 */
static int	set_enemy_alt(t_all *all)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	y = 0;
	while (all->map[y])
	{
		while (all->map[y][x])
		{
			if (all->map[y][x] == '0')
			{
				all->map2[y][x] = 'X';
				all->game->mapinfo.enemy_x = x;
				all->game->mapinfo.enemy_y = y;
				draw_enemy(all);
				return (1);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

/**
 * Finds a valid initial position for the enemy. (If there is no valid position
 * for the enemy, 'set_enemy_alt' will be called to scan a different 
 * portion of the map for a valid starting position).
 * @param[in] all struct containing mlx, map, and game
 * @return nothing
 */
int	set_enemy(t_all *all)
{
	unsigned int	x;
	unsigned int	y;

	x = all->game->mapinfo.length_of_first_row / 2;
	y = all->game->mapinfo.number_of_rows / 2;
	while (all->map[y])
	{
		while (all->map[y][x])
		{
			if (all->map[y][x] == '0')
			{
				all->map2[y][x] = 'X';
				all->game->mapinfo.enemy_x = x;
				all->game->mapinfo.enemy_y = y;
				draw_enemy(all);
				return (1);
			}
			x++;
		}
		x = 0;
		y++;
	}
	if (set_enemy_alt(all))
		return (1);
	return (0);
}

/**
 * Draws the enemy onto the map.
 * 
 * @param[in] mlx main MLX handle. Handles important program data.
 * @param[in] map map of the game
 * @param[in] game overall game struct with all the information in it
 * @param[in] enemy_img image struct where the enemy is stored to
 * 
 * @return nothing
 */
void	update_light(t_all *all)
{
	int	x;
	int	y;

	if (all->game->mapinfo.moves % 2 == 1)
		mlx_delete_image(all->mlx, all->game->images.light_img);
	else
	{
		all->game->images.light_img = mlx_new_image(all->mlx,
				all->game->mapinfo.win_width, all->game->mapinfo.win_height);
		y = 0;
		while (all->map2[y])
		{
			x = 0;
			while (all->map2[y][x])
			{
				if (all->map2[y][x] == 'X')
					mlx_draw_texture(all->game->images.light_img,
						all->game->textures.light, x * BLOCKSIZE,
						y * BLOCKSIZE);
				x++;
			}
			y++;
		}
		mlx_image_to_window(all->mlx, all->game->images.light_img, 0, 0);
	}
}

/**
 * Finds a valid initial position for the enemy
 * @param[in] all struct containing mlx, map, and game
 * @return nothing
 */
int	set_enemy_standard(t_all *all)
{
	unsigned int	x;
	unsigned int	y;

	x = 6;
	y = 5;
	if (all->game->mapinfo.length_of_first_row > 9
		&& all->game->mapinfo.number_of_rows > 8)
	{
		if (all->map[y][x] == '0')
		{
			all->map2[y][x] = 'X';
			all->game->mapinfo.enemy_x = x;
			all->game->mapinfo.enemy_y = y;
			draw_enemy(all);
			return (1);
		}
	}
	return (0);
}
