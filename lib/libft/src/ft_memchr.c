/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 12:42:26 by cpost         #+#    #+#                 */
/*   Updated: 2021/10/28 12:42:27 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		t;
	size_t				i;
	const unsigned char	*x;

	i = 0;
	x = s;
	t = c;
	while (i < n)
	{
		if (x[i] == t)
			return ((void *)&x[i]);
		i++;
	}
	return (0);
}
