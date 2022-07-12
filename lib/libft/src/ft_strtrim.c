/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 12:43:31 by cpost         #+#    #+#                 */
/*   Updated: 2021/10/28 12:43:32 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_setcompare(char s1, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s1)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	first;
	char	*new;

	first = 0;
	if (!s1 || !set)
		return (0);
	while (ft_setcompare((char)s1[first], (char *)set))
		first++;
	if (!s1[first])
		return (ft_strdup(""));
	i = ft_strlen((char *)s1) - 1;
	while (ft_setcompare((char)s1[i], (char *)set))
		i--;
	i++;
	new = malloc((i - first + 1) * sizeof(char));
	if (!new)
		return (0);
	ft_memcpy(new, s1 + first, i - first);
	new[i - first] = 0;
	return (new);
}
