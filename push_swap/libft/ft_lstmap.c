/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 08:21:26 by ldrieske          #+#    #+#             */
/*   Updated: 2023/06/01 15:29:37 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * ft_lstmap
 * 
 * t_list *lst : address of a pointer to a node
 * void *(*f)(void *) : address of a function used to iterate on lst
 * void (*del)(void *) : address of a function used to delete the content
 * 	of a node if needed
 * 
 * Returns the new list or NULL if the allocation failed
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*node;

	if (!lst || !f || !del)
		return (0);
	new = 0;
	while (lst)
	{
		node = ft_lstnew(f(lst->content));
		if (!node)
		{
			ft_lstclear (&new, del);
			return (0);
		}
		ft_lstadd_back(&new, node);
		lst = lst->next;
	}
	return (new);
}
