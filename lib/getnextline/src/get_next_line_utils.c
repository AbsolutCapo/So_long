/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/11 12:23:24 by cpost         #+#    #+#                 */
/*   Updated: 2022/06/23 13:35:59 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_calloc_gnl(int size)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = malloc(size * sizeof(char) + 1);
	if (ptr)
	{
		while (size > 0)
		{
			ptr[i] = '\0';
			i++;
			size--;
		}
	}
	return (ptr);
}

int	ft_count_str_length(char *total_str)
{
	int	i;

	i = 0;
	while (total_str[i] != '\0')
	{
		if (total_str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i + 1);
}

char	*ft_memcpy_gnl(char *src, char *dest, size_t n)
{
	size_t	i;

	i = 0;
	if (!src && !dest)
		return (0);
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

int	ft_check_return(char *return_str, char *total_str)
{
	int	i;

	i = 0;
	if (total_str[0] == '\0')
		return (1);
	while (return_str[i] != '\0' )
	{
		if (return_str[i] == '\n')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_return_add_size(char *return_str, int size)
{
	char	*new_return;
	int		i;

	i = 0;
	while (return_str[i] != '\0')
		i++;
	new_return = ft_calloc_gnl((i + size) * sizeof(char));
	if (new_return == NULL)
	{
		free(return_str);
		return (NULL);
	}
	i = 0;
	while (return_str[i] != '\0')
	{
		new_return[i] = return_str[i];
		i++;
	}
	free(return_str);
	return (new_return);
}
