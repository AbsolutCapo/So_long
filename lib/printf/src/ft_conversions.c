/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_conversions.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/06 13:03:28 by cpost         #+#    #+#                 */
/*   Updated: 2022/04/05 12:42:15 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_putchar(int str, int i, int *c)
{
	write(1, &str, 1);
	*c += 1;
	return (i + 1);
}

int	ft_putstr(char *s, int i, int *c)
{
	int	count;

	count = 0;
	if (!s)
		return (ft_putstr("(null)", i, c));
	while (s[count])
	{
		write(1, &s[count], 1);
		*c += 1;
		count++;
	}
	return (i + 1);
}

int	ft_putnbr(long n, int i, int *c)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		*c += 11;
		return (i + 1);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		*c += 1;
		n = -n;
	}
	if (n / 10 != 0)
		ft_putnbr(n / 10, i, c);
	n = (n % 10) + '0';
	write(1, &n, 1);
		*c += 1;
	return (i + 1);
}

int	ft_puthexa(unsigned long n, int i, int *c, int x)
{
	char	*str;

	if (n / 16 != 0)
		ft_puthexa(n / 16, i, c, x);
	n = (n % 16);
	if (x == 1)
		str = "0123456789ABCDEF";
	if (x == 0)
		str = "0123456789abcdef";
	write(1, &str[n], 1);
		*c += 1;
	return (i + 1);
}

int	ft_putptr(unsigned long n, int i, int *c)
{
	write(1, "0x", 2);
	*c += 2;
	return (ft_puthexa(n, i, c, 0));
}
