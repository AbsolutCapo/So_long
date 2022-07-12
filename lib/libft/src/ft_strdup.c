/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 12:43:02 by cpost         #+#    #+#                 */
/*   Updated: 2021/10/28 12:43:03 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*x;
	int		i;

	i = 0;
	x = malloc(ft_strlen((char *)s) + 1);
	if (!x)
		return (0);
	while (s[i])
	{
		x[i] = s[i];
		i++;
	}
	x[i] = 0;
	return (x);
}
