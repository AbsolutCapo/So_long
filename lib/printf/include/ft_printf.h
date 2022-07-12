/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/17 16:08:42 by cpost         #+#    #+#                 */
/*   Updated: 2021/12/17 16:08:49 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_putchar(int str, int i, int *c);
int	ft_putstr(char *s, int i, int *c);
int	ft_putnbr(long n, int i, int *c);
int	ft_puthexa(unsigned long n, int i, int *c, int x);
int	ft_putptr(unsigned long n, int i, int *c);
#endif