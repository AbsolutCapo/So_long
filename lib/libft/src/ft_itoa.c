/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 12:41:39 by cpost         #+#    #+#                 */
/*   Updated: 2021/10/28 12:41:40 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_neg(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

static int	ft_convert_neg(char *str, int n)
{
	str[0] = '-';
	n = -n;
	return (n);
}

static int	ft_count_num(int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		neg;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	neg = ft_neg(n);
	i = ft_count_num(n) + neg;
	str = malloc((i + 1) * sizeof(char));
	if (!str)
		return (0);
	str[i] = 0;
	i--;
	if (neg)
		n = ft_convert_neg(str, n);
	while (n > 0)
	{
		str[i] = (n % 10) + 48;
		n /= 10;
		i--;
	}
	return (str);
}
