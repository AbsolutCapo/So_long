/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_textures.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/09 15:28:51 by cpost         #+#    #+#                 */
/*   Updated: 2022/05/25 14:17:16 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "MLX42/MLX42.h"

/**
 * Draws the player onto the map.
 * 
 * @param[in] mlx main MLX handle. Handles important program data.
 * @param[in] map map of the game
 * @param[in] game overall game struct with all the information in it
 * @param[in] player_img image struct where the base map is stored to
 * 
 * @return nothing
 */
void	draw_player(t_all *all, mlx_image_t *player_img)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (!player_img)
		free_all_and_exit(all, 1);
	while (all->map[y])
	{
		while (all->map[y][x])
		{
			if (all->map[y][x] == 'P')
				mlx_draw_texture(player_img, all->game->textures.player,
					x * BLOCKSIZE, y * BLOCKSIZE);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_image_to_window(all->mlx, player_img, 0, 0);
}

/**
 * Draws the exit onto the map.
 * 
 * @param[in] mlx main MLX handle. Handles important program data.
 * @param[in] map map of the game
 * @param[in] game overall game struct with all the information in it
 * @param[in] exit_img image struct where the base map is stored to
 * 
 * @return nothing
 */
static void	draw_exit(t_all *all, mlx_image_t *exit_img)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (!exit_img)
		free_all_and_exit(all, 1);
	while (all->map[y])
	{
		while (all->map[y][x])
		{
			if (all->map[y][x] == 'E')
				mlx_draw_texture(exit_img, all->game->textures.exit,
					x * BLOCKSIZE, y * BLOCKSIZE);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_image_to_window(all->mlx, exit_img, 0, 0);
}

/**
 * Draws the collectibles onto the map.
 * 
 * @param[in] mlx main MLX handle. Handles important program data.
 * @param[in] map map of the game
 * @param[in] game overall game struct with all the information in it
 * @param[in] collectible_img image struct where the base map is stored to
 * 
 * @return nothing
 */
void	draw_collectibles(t_all *all, mlx_image_t *collectible_img)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (!collectible_img)
		free_all_and_exit(all, 1);
	while (all->map[y])
	{
		while (all->map[y][x])
		{
			if (all->map[y][x] == 'C')
				mlx_draw_texture(collectible_img,
					all->game->textures.collectible,
					x * BLOCKSIZE, y * BLOCKSIZE);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_image_to_window(all->mlx, collectible_img, 0, 0);
}

/**
 * Draws the background image layer (ground and wall tiles).
 * 
 * @param[in] mlx main MLX handle. Handles important program data.
 * @param[in] map map of the game
 * @param[in] game overall game struct with all the information in it
 * @param[in] g_img image struct where the base map is stored to
 * 
 * @return Pointer to the image buffer, if it failed to allocate then NULL.
 */
static void	draw_background(t_all *all, mlx_image_t *background_img)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (!background_img)
		free_all_and_exit(all, 1);
	while (all->map[y])
	{
		while (all->map[y][x])
		{
			if (all->map[y][x] == '1')
				mlx_draw_texture(background_img, all->game->textures.wall,
					x * BLOCKSIZE, y * BLOCKSIZE);
			else
				mlx_draw_texture(background_img, all->game->textures.ground,
					x * BLOCKSIZE, y * BLOCKSIZE);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_image_to_window(all->mlx, background_img, 0, 0);
}

/**
 * Initializes functions that print all the map layers.
 * 
 * @param[in] mlx main MLX handle. Handles important program data.
 * @param[in] map map of the game
 * @param[in] game overall game struct with all the information in it
 * 
 * @return Nothing
 */
void	draw_base_map(t_all *all)
{
	all->game->images.background_img = mlx_new_image(all->mlx,
			all->game->mapinfo.win_width, all->game->mapinfo.win_height);
	if (!all->game->images.background_img)
		free_all_and_exit(all, 1);
	all->game->images.player_img = mlx_new_image(all->mlx,
			all->game->mapinfo.win_width, all->game->mapinfo.win_height);
	if (!all->game->images.player_img)
		free_all_and_exit(all, 1);
	all->game->images.collectible_img = mlx_new_image(all->mlx,
			all->game->mapinfo.win_width, all->game->mapinfo.win_height);
	if (!all->game->images.collectible_img)
		free_all_and_exit(all, 1);
	all->game->images.exit_img = mlx_new_image(all->mlx,
			all->game->mapinfo.win_width, all->game->mapinfo.win_height);
	if (!all->game->images.exit_img)
		free_all_and_exit(all, 1);
	all->game->images.enemy_img = mlx_new_image(all->mlx,
			all->game->mapinfo.win_width, all->game->mapinfo.win_height);
	if (!all->game->images.enemy_img)
		free_all_and_exit(all, 1);
	draw_background(all, all->game->images.background_img);
	draw_collectibles(all, all->game->images.collectible_img);
	draw_exit(all, all->game->images.exit_img);
	draw_player(all, all->game->images.player_img);
}
