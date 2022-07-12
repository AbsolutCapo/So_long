/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 12:40:05 by cpost         #+#    #+#                 */
/*   Updated: 2022/04/20 13:30:04 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

static int	ft_getnumber(const char *ptr, int c)
{
	int	num;

	num = 0;
	while (*ptr >= '0' && *ptr <= '9')
	{
		num = (*ptr - 48) + (num * 10);
		ptr++;
	}
	return (num * c);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	c;

	i = 0;
	c = 1;
	while (nptr[i] == '\n' || nptr[i] == '\t' || nptr[i] == '\v'
		|| nptr[i] == '\f' || nptr[i] == '\r' || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			c = -c;
		i++;
	}
	if (nptr[i] >= '0' && nptr[i] <= '9')
		return (ft_getnumber(nptr + i, c));
	return (0);
}
