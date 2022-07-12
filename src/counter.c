/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   counter.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/17 16:53:48 by cpost         #+#    #+#                 */
/*   Updated: 2022/05/30 15:33:13 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "so_long.h"
#include "libft.h"
#include <stdlib.h>

/**
 * Updates the counter if player moves.
 * @param[in] all struct containing mlx, map, and game
 * @return Nothing
 */
void	update_counter(t_all *all)
{
	char	*str;

	str = ft_itoa(all->game->mapinfo.moves);
	if (!str)
		free_all_and_exit(all, EXIT_FAILURE);
	mlx_delete_image(all->mlx, all->game->images.counter_img);
	all->game->images.counter_img = mlx_put_string(all->mlx, str, 10, 10);
	free(str);
}

/**
 * Creates an image with a number in it. This will be the counter.
 * @param[in] all struct containing mlx, map, and game
 * @return Nothing
 */
void	set_counter_zero(t_all *all)
{
	char	*str;

	str = ft_itoa(all->game->mapinfo.moves);
	if (!str)
		free_all_and_exit(all, EXIT_FAILURE);
	all->game->images.counter_img = mlx_put_string(all->mlx, str, 10, 10);
	free(str);
}
