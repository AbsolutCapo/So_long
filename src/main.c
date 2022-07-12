/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/04 14:47:08 by cpost         #+#    #+#                 */
/*   Updated: 2022/07/01 17:21:31 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

/**
 * @param[in] argc the amount of arguments inputted into the program
 * @param[in] argv the arguments inputted into the program
 * 
 * @return 1 if there is an error, 0 if program terminated succesfully
 */
int	main(int argc, char **argv)
{
	t_all	*all;

	all = malloc(sizeof(t_all));
	if (!all)
		free_all_and_exit(all, EXIT_FAILURE);
	set_all_to_null(all);
	if (check_argument(argc, argv[1]))
		free_all_and_exit(all, EXIT_FAILURE);
	all->map = split_text_file_to_array(argv[1], NULL);
	if (!all->map)
		free_all_and_exit(all, EXIT_FAILURE);
	all->map2 = split_text_file_to_array(argv[1], NULL);
	if (!all->map2)
		free_all_and_exit(all, EXIT_FAILURE);
	all->game = malloc(sizeof(t_game));
	if (!all->game)
		free_all_and_exit(all, EXIT_FAILURE);
	set_starting_values(all);
	get_map_info(all->map, all->game);
	if (check_for_invalid_map(all->map, all->game))
		free_all_and_exit(all, EXIT_FAILURE);
	start_game(all, all->game->mapinfo.win_width,
		all->game->mapinfo.win_height);
	return (EXIT_SUCCESS);
}
