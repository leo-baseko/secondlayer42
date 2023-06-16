/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mechanicalturk_utils3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:29:28 by ldrieske          #+#    #+#             */
/*   Updated: 2023/06/16 23:20:40 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
 * ft_find_place_b
 * 
 * t_stacknode stack_b : stack b duh
 * int nbr_push : the number we need to push in the b stack
 * 
 * Finds the correct place (index) of the number in stack_b.
*/
int	ft_find_place_b(t_stacknode *stack_b, int nbr_push)
{
	int			i;
	t_stacknode	*tmp;

	i = 1;
	if (nbr_push > stack_b->data && nbr_push < lstlast(stack_b)->data)
		i = 0;
	else if (nbr_push > ft_max(stack_b) || nbr_push < ft_min(stack_b))
		i = ft_find_index(stack_b, ft_max(stack_b));
	else
	{
		tmp = stack_b->next;
		while (tmp->data > nbr_push || stack_b->data < nbr_push)
		{
			stack_b = stack_b->next;
			tmp = stack_b->next;
			i++;
		}
	}
	return (i);
}

/*
 * ft_find_place_a
 * 
 * t_stacknode stack_a : stack a duh
 * int nbr_push : the number we need to push in the a stack
 * 
 * Finds the correct place (index) of the number in stack_a.
*/
int	ft_find_place_a(t_stacknode *stack_a, int nbr_push)
{
	int			i;
	t_stacknode	*tmp;

	i = 1;
	if (stack_a == NULL || lstlast(stack_a) == NULL)
		return (0);
	if (nbr_push < stack_a->data && nbr_push > lstlast(stack_a)->data)
		i = 0;
	else if (nbr_push > ft_max(stack_a) || nbr_push < ft_min(stack_a))
		i = ft_find_index(stack_a, ft_min(stack_a));
	else
	{
		tmp = stack_a->next;
		while (stack_a->data > nbr_push
			|| (tmp != NULL && tmp->data < nbr_push))
		{
			stack_a = stack_a->next;
			tmp = stack_a->next;
			i++;
		}
	}
	return (i);
}

/*
 * lstlast
 * 
 * t_stacknode *lst : stack
 * 
 * Returns the last element of the stack
*/
t_stacknode	*lstlast(t_stacknode *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/*
 * lstsize
 * 
 * t_stacknode *lst : stack
 * 
 * Returns the size of the stack
*/
int	lstsize(t_stacknode *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

/*
 * ft_min
 * 
 * t_stacknode a : stack
 * 
 * Returns the smallest element of the stack
*/
int	ft_min(t_stacknode *a)
{
	int		i;

	i = a->data;
	while (a)
	{
		if (a->data < i)
			i = a->data;
		a = a->next;
	}
	return (i);
}
