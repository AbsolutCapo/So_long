/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/11 12:23:43 by cpost         #+#    #+#                 */
/*   Updated: 2022/06/23 13:35:34 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*ft_calloc_gnl(int size);
int		ft_count_str_length(char *total_str);
char	*ft_memcpy_gnl(char *src, char *dest, size_t n);
int		ft_check_return(char *return_str, char *total_str);
char	*ft_return_add_size(char *return_str, int size);
char	*ft_strjoin_gnl(char *return_str, char *total_str);
void	ft_set_total_to_zero(char *total, int x);
char	*ft_remove_return_from_total(char *total, int i, int x);
void	*ft_cut_total(char *total_str, int r_read);
#endif