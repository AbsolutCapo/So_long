/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 12:43:11 by cpost         #+#    #+#                 */
/*   Updated: 2021/10/28 12:43:12 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	x;
	size_t	y;

	i = ft_strlen(dst);
	y = ft_strlen(src) + i;
	x = 0;
	if (i >= size)
		return (size + ft_strlen(src));
	while (i < size - 1 && src[x])
	{
		dst[i] = src[x];
		i++;
		x++;
	}
	dst[i] = 0;
	return (y);
}
