/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 08:15:45 by ldrieske          #+#    #+#             */
/*   Updated: 2023/06/01 15:29:47 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * ft_lstdelone
 * 
 * t_list *lst : the node we wants to free
 * void (*del)(void *) : address used to delete the content
 * 
 * Frees the memory of a node's content using the function del.
 * It does not free next
*/

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || ! del)
		return ;
	del(lst->content);
	free(lst);
}
