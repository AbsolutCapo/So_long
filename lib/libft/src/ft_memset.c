/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 12:42:36 by cpost         #+#    #+#                 */
/*   Updated: 2021/10/28 12:42:37 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*x;

	x = s;
	while (n > 0)
	{
		*x = c;
		n--;
		x++;
	}
	return (s);
}
