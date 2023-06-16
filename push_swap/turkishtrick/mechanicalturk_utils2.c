/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mechanicalturk_utils2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:29:25 by ldrieske          #+#    #+#             */
/*   Updated: 2023/06/16 20:39:44 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
 * ft_max
 * 
 * t_stacknode a : stack a
 * 
 * This function finds and returns the biggest number in the given stack
*/
int	ft_max(t_stacknode *a)
{
	int		i;

	i = a->data;
	while (a)
	{
		if (a->data > i)
			i = a->data;
		a = a->next;
	}
	return (i);
}

/*
 * ft_case_rrarb_a
 * 
 * t_stacknode a : stack a
 * t_stacknode b : stack b
 * int c : value of the number
 * 
 * Calculates the required amount of rotation with the rra + rb
*/
int	ft_case_rrarb_a(t_stacknode *a, t_stacknode *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_place_a(a, c))
		i = lstsize(a) - ft_find_place_a(a, c);
	i = ft_find_index(b, c) + i;
	return (i);
}

/*
 * ft_case_rarb_a
 * 
 * t_stacknode a : stack a
 * t_stacknode b : stack b
 * int c : value of the number
 * 
 * Calculates the required amount of rotation with the ra + rb
*/
int	ft_case_rarb_a(t_stacknode *a, t_stacknode *b, int c)
{
	int	i;

	i = ft_find_place_a(a, c);
	if (i < ft_find_index(b, c))
		i = ft_find_index(b, c);
	return (i);
}

/*
 * ft_case_rrarrb_a
 * 
 * t_stacknode a : stack a
 * t_stacknode b : stack b
 * int c : value of the number
 * 
 * Calculates the required amount of rotation with the rra + rrb
*/
int	ft_case_rrarrb_a(t_stacknode *a, t_stacknode *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_place_a(a, c))
		i = lstsize(a) - ft_find_place_a(a, c);
	if ((i < (lstsize(b) - ft_find_index(b, c))) && ft_find_index(b, c))
		i = lstsize(b) - ft_find_index(b, c);
	return (i);
}

/*
 * ft_case_rarrb_a
 * 
 * t_stacknode a : stack a
 * t_stacknode b : stack b
 * int c : value of the number
 * 
 * Calculates the required amount of rotation with the ra + rrb
*/
int	ft_case_rarrb_a(t_stacknode *a, t_stacknode *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_index(b, c))
		i = lstsize(b) - ft_find_index(b, c);
	i = ft_find_place_a(a, c) + i;
	return (i);
}
