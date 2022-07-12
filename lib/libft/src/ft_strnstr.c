/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 12:43:25 by cpost         #+#    #+#                 */
/*   Updated: 2021/10/28 12:43:26 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static int	ft_scan(const char *big, const char *little, size_t i, size_t n)
{
	int	x;

	x = 0;
	while (little[x] != '\0')
	{
		if (i >= n)
			return (2);
		else if (little[x] == big[i])
		{
			i++;
			x++;
		}
		else if (little[x] != big[i])
			return (0);
	}
	return (1);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t			i;

	i = 0;
	if (little[0] == '\0')
		return ((char *)&big[i]);
	if (len == 0)
		return (0);
	while (big[i] && i < len)
	{
		if (big[i] == little[0])
		{
			if (ft_scan(big, little, i, len) == 2)
				return (0);
			if (ft_scan(big, little, i, len) == 1)
				return ((char *)&big[i]);
		}
		i++;
	}
	return (0);
}
