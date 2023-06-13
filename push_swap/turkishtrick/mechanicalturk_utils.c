/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mechanicalturk_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:03:01 by ldrieske          #+#    #+#             */
/*   Updated: 2023/06/13 23:37:36 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
 * ft_rotate_type_ba
 * 
 * a : stack a
 * b : stack b
 * 
 * Return the cheapest value of rotation combination
 * to sort the stack in the A stack
*/
int	ft_rotate_type_ba(t_stacknode *a, t_stacknode *b)
{
	int			i;
	t_stacknode	*tmp;

	tmp = b;
	i = ft_case_rrarrb_a(a, b, b->data);
	while (tmp)
	{
		if (i > ft_case_rarb_a(a, b, tmp->data))
			i = ft_case_rarb_a(a, b, tmp->data);
		if (i > ft_case_rrarrb_a(a, b, tmp->data))
			i = ft_case_rrarrb_a(a, b, tmp->data);
		if (i > ft_case_rarrb_a(a, b, tmp->data))
			i = ft_case_rarrb_a(a, b, tmp->data);
		if (i > ft_case_rrarb_a(a, b, tmp->data))
			i = ft_case_rrarb_a(a, b, tmp->data);
		tmp = tmp->next;
	}
	return (i);
}

/*
 * ft_rotate_type_ab
 * 
 * a : stack a
 * b : stack b
 * 
 * Return the cheapest value of rotation combination
 * to sort the stack in the B stack
*/
int	ft_rotate_type_ab(t_stacknode *a, t_stacknode *b)
{
	int			i;
	t_stacknode	*tmp;

	tmp = a;
	i = ft_case_rrarrb(a, b, a->data);
	while (tmp)
	{
		if (i > ft_case_rarb(a, b, tmp->data))
			i = ft_case_rarb(a, b, tmp->data);
		if (i > ft_case_rrarrb(a, b, tmp->data))
			i = ft_case_rrarrb(a, b, tmp->data);
		if (i > ft_case_rarrb(a, b, tmp->data))
			i = ft_case_rarrb(a, b, tmp->data);
		if (i > ft_case_rrarb(a, b, tmp->data))
			i = ft_case_rrarb(a, b, tmp->data);
		tmp = tmp->next;
	}
	return (i);
}
