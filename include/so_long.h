/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/06 10:42:29 by cpost         #+#    #+#                 */
/*   Updated: 2022/07/01 14:43:35 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BLOCKSIZE 128
# include "MLX42/MLX42.h"

/**
 * Containes map information
 */
typedef struct s_mapinfo {
	unsigned int	number_of_players;
	unsigned int	number_of_collectibles;
	unsigned int	number_of_exits;
	unsigned int	number_of_rows;
	unsigned int	length_of_first_row;
	unsigned int	win_width;
	unsigned int	win_height;
	unsigned int	player_x;
	unsigned int	player_y;
	unsigned int	enemy_x;
	unsigned int	enemy_y;
	unsigned int	exit_x;
	unsigned int	exit_y;
	unsigned int	moves;
	unsigned int	dist_up;
	unsigned int	dist_left;
	unsigned int	dist_down;
	unsigned int	dist_right;
}				t_mapinfo;

/**
 * Containes the paths to the texture png's
 */
typedef struct s_textures {
	struct mlx_texture	*player;
	struct mlx_texture	*ground;
	struct mlx_texture	*wall;
	struct mlx_texture	*collectible;
	struct mlx_texture	*exit;
	struct mlx_texture	*enemy;
	struct mlx_texture	*light;
}				t_textures;

/**
 * Containes the images of the game
 */
typedef struct s_images {
	mlx_image_t	*background_img;
	mlx_image_t	*player_img;
	mlx_image_t	*collectible_img;
	mlx_image_t	*exit_img;
	mlx_image_t	*enemy_img;
	mlx_image_t	*counter_img;
	mlx_image_t	*light_img;
}				t_images;

/**
 * Parent struct containing other structs
 */
typedef struct s_game {
	t_mapinfo	mapinfo;
	t_textures	textures;
	t_images	images;
}				t_game;

/**
 * Struct containing map, game and mlx struct
 */
typedef struct s_all {
	char	**map;
	char	**map2;
	t_game	*game;
	mlx_t	*mlx;
}				t_all;

int		check_argument(int argc, char *argv);
void	set_starting_values(t_all *all);
void	execute_hook(mlx_key_data_t keydata, void *param);
char	**split_text_file_to_array(char *filename, char *total_string);
void	get_map_info(char **map, t_game *game);
int		check_for_invalid_map(char **map, t_game *game);
int32_t	start_game(t_all *all, unsigned int window_width,
			unsigned int window_height);
void	draw_base_map(t_all *all);
void	draw_collectibles(t_all *all, mlx_image_t *collectible_img);
void	draw_player(t_all *all, mlx_image_t *player_img);
int		check_valid_move(char direction, t_all *all, unsigned int x,
			unsigned int y);
void	check_collectibles(t_all *all, unsigned int x, unsigned int y,
			char direction);
void	move_player(t_all *all, unsigned int x, unsigned int y,
			char direction);
void	check_exit(t_all *all, unsigned int x, unsigned int y);
void	set_counter_zero(t_all *all);
void	update_counter(t_all *all);
void	draw_enemy(t_all *all);
int		set_enemy(t_all *all);
void	update_enemy(t_all *all, unsigned int x, unsigned int y);
void	update_light(t_all *all);
void	check_enemy(t_all *all, unsigned int x, unsigned int y);
void	free_all_and_exit(t_all *all, int exit_code);
void	set_all_to_null(t_all *all);
void	free_map(char **map);
void	check_for_double_newlines(char *total_string);
int		set_enemy_standard(t_all *all);
void	set_window_definitions(t_game *game);

#endif