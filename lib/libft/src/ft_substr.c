/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 12:43:34 by cpost         #+#    #+#                 */
/*   Updated: 2021/10/28 12:43:35 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stddef.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*x;
	unsigned int	i;

	if (!s)
		return (0);
	i = ft_strlen((char *)s);
	if (!len || start >= i)
		return (ft_strdup(""));
	if (len < i - start)
		x = malloc((len + 1) * sizeof(char));
	else
		x = malloc(((i - start) + 1) * sizeof(char));
	if (!x)
		return (0);
	ft_strlcpy(x, s + start, len + 1);
	return (x);
}
