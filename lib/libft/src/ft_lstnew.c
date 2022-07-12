/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 12:41:58 by cpost         #+#    #+#                 */
/*   Updated: 2021/10/28 16:07:02 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	struct s_list	*new_block;

	new_block = malloc(sizeof(*new_block));
	if (!new_block)
		return (NULL);
	new_block->content = content;
	new_block->next = NULL;
	return (new_block);
}
