/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 08:17:40 by ldrieske          #+#    #+#             */
/*   Updated: 2022/11/16 13:54:08 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * ft_lstclear
 * 
 * t_list **lst : the address of a pointer to a node
 * void (*del)(void *) : the address of the function used to delete the 
 * 	content of the node
 * 
 * Deletes and frees the given node and every successor of that node
 * The pointer of the list is set to NULL
*/

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*new;
	t_list	*next;

	if (lst && del && *lst)
	{
		new = *lst;
		while (new)
		{
			next = new->next;
			ft_lstdelone(new, del);
			new = next;
		}
		*lst = 0;
	}
}
