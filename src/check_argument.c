/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_argument.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/20 13:47:39 by cpost         #+#    #+#                 */
/*   Updated: 2022/06/27 18:51:38 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_printf.h"

int	check_argument(int argc, char *argv)
{
	int	i;

	i = 0;
	if (argc != 2)
		return (1);
	while (argv[i])
		i++;
	if (i < 4 || argv[i - 1] != 'r' || argv[i - 2] != 'e' || argv[i - 3] != 'b'
		|| argv[i - 4] != '.')
	{
		ft_printf("Only .ber files allowed\n");
		return (1);
	}
	return (0);
}
