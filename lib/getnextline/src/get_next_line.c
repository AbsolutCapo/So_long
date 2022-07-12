/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/11 12:23:20 by cpost         #+#    #+#                 */
/*   Updated: 2022/06/23 13:36:08 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_gnl(char *return_str, char *total_str)
{
	int	i;
	int	x;

	i = 0;
	while (return_str[i] != '\0')
		i++;
	x = 0;
	while (total_str[x] != '\0' && total_str[x] != '\n')
	{
		return_str[i] = total_str[x];
		i++;
		x++;
	}
	if (total_str[x] == '\n')
	{
		return_str[i] = '\n';
		i++;
	}
	return_str[i] = '\0';
	return (return_str);
}

void	ft_set_total_to_zero(char *total, int x)
{
	while (x <= BUFFER_SIZE)
	{
		total[x] = '\0';
		x++;
	}
	return ;
}

char	*ft_remove_return_from_total(char *total, int i, int x)
{
	while (total[i] != '\0' && total[i] != '\n')
		i++;
	if (total[i] == '\0')
	{
		while (x <= BUFFER_SIZE)
		{
			total[x] = '\0';
			x++;
		}
		return (total);
	}
	if (total[i] == '\n')
		i++;
	while (total[i] != '\0')
	{
		total[x] = total[i];
		x++;
		i++;
	}
	ft_set_total_to_zero(total, x);
	return (total);
}

char	*fill_return(char *return_str, char *total_str, int r_read, int fd)
{
	int	size;

	r_read = read(fd, total_str, BUFFER_SIZE);
	if (r_read < 0)
	{
		free(return_str);
		return (NULL);
	}
	ft_set_total_to_zero(total_str, r_read);
	size = ft_count_str_length(total_str);
	return_str = ft_return_add_size(return_str, size);
	if (return_str == NULL)
		return (NULL);
	return_str = ft_strjoin_gnl(return_str, total_str);
	return (return_str);
}

char	*get_next_line(int fd)
{
	char		*return_str;
	static char	total_str[OPEN_MAX][BUFFER_SIZE + 1];
	int			size;
	int			r_read;

	if (BUFFER_SIZE <= 0 || fd > OPEN_MAX || fd < 0)
		return (NULL);
	r_read = 1;
	if (total_str[fd][0] == '\0')
		r_read = read(fd, total_str[fd], BUFFER_SIZE);
	if (r_read <= 0)
		return (NULL);
	size = ft_count_str_length(total_str[fd]);
	return_str = ft_calloc_gnl(size + 1);
	if (return_str == NULL)
		return (NULL);
	return_str = ft_memcpy_gnl(total_str[fd], return_str, size);
	while (ft_check_return(return_str, total_str[fd]) == 0)
	{
		return_str = fill_return(return_str, total_str[fd], r_read, fd);
		if (return_str == NULL)
			return (NULL);
	}
	ft_remove_return_from_total(total_str[fd], 0, 0);
	return (return_str);
}
