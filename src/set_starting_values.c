/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_starting_values.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 13:01:51 by cpost         #+#    #+#                 */
/*   Updated: 2022/05/30 14:05:22 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "MLX42/MLX42.h"
#include <stdlib.h>
#include <unistd.h>

/**
 * Sets the default value of images.
 * 
 * @param[in] game The overall struct with all the game information in it
 * 
 * @return Nothing
 */
static void	set_images(t_all *all)
{
	all->game->images.background_img = 0;
	all->game->images.collectible_img = 0;
	all->game->images.counter_img = 0;
	all->game->images.enemy_img = 0;
	all->game->images.exit_img = 0;
	all->game->images.light_img = 0;
	all->game->images.player_img = 0;
}

/**
 * Sets the default value of the textures.
 * 
 * @param[in] game The overall struct with all the game information in it
 * 
 * @return Nothing
 */
static void	set_textures(t_all *all)
{
	all->game->textures.player = mlx_load_png("./png/player.png");
	if (!all->game->textures.player)
		free_all_and_exit(all, 1);
	all->game->textures.ground = mlx_load_png("./png/ground.png");
	if (!all->game->textures.ground)
		free_all_and_exit(all, 1);
	all->game->textures.wall = mlx_load_png("./png/wall.png");
	if (!all->game->textures.wall)
		free_all_and_exit(all, 1);
	all->game->textures.collectible = mlx_load_png("./png/collectible.png");
	if (!all->game->textures.collectible)
		free_all_and_exit(all, 1);
	all->game->textures.exit = mlx_load_png("./png/exit.png");
	if (!all->game->textures.exit)
		free_all_and_exit(all, 1);
	all->game->textures.enemy = mlx_load_png("./png/enemy.png");
	if (!all->game->textures.enemy)
		free_all_and_exit(all, 1);
	all->game->textures.light = mlx_load_png("./png/light.png");
	if (!all->game->textures.light)
		free_all_and_exit(all, 1);
}

/**
 * Sets the default value of some variables to 0. Also some paths to
 * game textures (png's) are set into variables.
 * 
 * @param[in] all The overall struct with all the information in it
 * 
 * @return Nothing
 */
void	set_starting_values(t_all *all)
{
	all->game->mapinfo.number_of_players = 0;
	all->game->mapinfo.number_of_collectibles = 0;
	all->game->mapinfo.number_of_exits = 0;
	all->game->mapinfo.number_of_rows = 0;
	all->game->mapinfo.length_of_first_row = 0;
	all->game->mapinfo.win_width = 0;
	all->game->mapinfo.win_height = 0;
	all->game->mapinfo.player_x = 0;
	all->game->mapinfo.player_y = 0;
	all->game->mapinfo.moves = 0;
	set_textures(all);
	set_images(all);
}

/**
 * Sets the pointers in the all struct to NULL.
 * 
 * @param[in] all The overall struct with all the game information in it
 * 
 * @return Nothing
 */
void	set_all_to_null(t_all *all)
{
	all->game = NULL;
	all->map2 = NULL;
	all->map = NULL;
	all->mlx = NULL;
}
