/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 12:42:55 by cpost         #+#    #+#                 */
/*   Updated: 2022/03/02 12:18:21 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_count_words(char *s, char c)
{
	size_t	i;
	size_t	wc;

	i = 0;
	wc = 0;
	while (s[i])
	{
		if (s[i] != c)
			wc++;
		while (s[i] != c && s[i])
			i++;
		while (s[i] == c && s[i])
			i++;
	}
	return (wc);
}

static char	*ft_new_word(char *s, char c)
{
	size_t	i;
	char	*str;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	str = malloc((i + 1) * sizeof(char));
	i = 0;
	while (s[i] != c && s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

static void	ft_freedom(char **origin, size_t x)
{
	while (x > 0)
	{
		x--;
		free(origin[x]);
	}
	free(origin);
}

static char	**ft_add_words(char **origin, char const *s, char c)
{
	size_t	i;
	size_t	x;

	x = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			origin[x] = ft_new_word((char *)s + i, c);
			if (!origin[x])
			{
				ft_freedom(origin, x);
				return (0);
			}
			x++;
		}
		while (s[i] != c && s[i])
			i++;
		while (s[i] == c && s[i])
			i++;
	}
	origin[x] = NULL;
	return (origin);
}

char	**ft_split(char const *s, char c)
{
	char	**origin;

	if (!s)
		return (0);
	origin = malloc(((ft_count_words((char *)s, c) + 1) * sizeof(char *)));
	if (!origin)
		return (0);
	origin = ft_add_words(origin, s, c);
	return (origin);
}
