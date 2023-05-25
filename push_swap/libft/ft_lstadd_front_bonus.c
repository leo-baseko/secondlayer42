/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:10:44 by ldrieske          #+#    #+#             */
/*   Updated: 2022/11/14 08:07:17 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * ft_lstadd_front
 * 
 * t_list **lst : the address of a pointer to the first link of a list
 * t_list *new : the address of a pointer to the node to be added to the list
 * 
 * Adds the node new in parameter at the beginning of the list
*/

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else if (*lst && new)
	{
		temp = *lst;
		new->next = temp;
		*lst = new;
	}
}
