/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 08:19:35 by ldrieske          #+#    #+#             */
/*   Updated: 2023/06/01 15:29:44 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * ft_lstiter
 * 
 * t_list *lst : address to a pointer of a node
 * void (*f)(void *) : address of the function used to iterate
 * 	on the list
 * 
 * Iterates lst and applies the function f on the content of each nodes
*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		(f)(lst->content);
		lst = lst->next;
	}
}
