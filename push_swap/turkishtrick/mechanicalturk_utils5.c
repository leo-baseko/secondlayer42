/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mechanicalturk_utils5.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:29:33 by ldrieske          #+#    #+#             */
/*   Updated: 2023/06/14 00:08:46 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
 * ft_case_rarb
 *
 * t_stacknode a : stack a
 * t_stacknode b : stack b
 * int c : value of the number in the stack
 * 
 * Calculates how many times we should rotate the stacks together
*/
int	ft_case_rarb(t_stacknode *a, t_stacknode *b, int c)
{
	int	i;

	i = ft_find_place_b(b, c);
	if (i < ft_find_index(a, c))
		i = ft_find_index(a, c);
	return (i);
}

/*
 * ft_case_rrarrb
 * 
 * t_stacknode a : stack a
 * t_stacknode b : stack b
 * int c : value of the number in the stack
 * 
 * Calculates how many times we should rotate the stacks together
*/
int	ft_case_rrarrb(t_stacknode *a, t_stacknode *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_place_b(b, c))
		i = lstsize(b) - ft_find_place_b(b, c);
	if ((i < (lstsize(a) - ft_find_index(a, c))) && ft_find_index(a, c))
		i = lstsize(a) - ft_find_index(a, c);
	return (i);
}

/*
 * ft_case_rrarrb
 * 
 * t_stacknode a : stack a
 * t_stacknode b : stack b
 * int c : value of the number in the stack
 * 
 * Calculates how many times we should rotate the stacks together
*/
int	ft_case_rrarb(t_stacknode *a, t_stacknode *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_index(a, c))
		i = lstsize(a) - ft_find_index(a, c);
	i = ft_find_place_b(b, c) + i;
	return (i);
}

/*
 * ft_case_rrarrb
 * 
 * t_stacknode a : stack a
 * t_stacknode b : stack b
 * int c : value of the number in the stack
 * 
 * Calculates how many times we should rotate the stacks together
*/
int	ft_case_rarrb(t_stacknode *a, t_stacknode *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_place_b(b, c))
		i = lstsize(b) - ft_find_place_b(b, c);
	i = ft_find_index(a, c) + i;
	return (i);
}

/*
 * ft_apply_rarb
 * 
 * t_stacknode a : stack a
 * t_stacknode b : stack b
 * int c : value of the number of the stack
 * char s : character we use to know if we're talking about the stack a or b
 * 
 * Rotates both the a and b stack in the same direction as required amount
*/
int	ft_apply_rarb(t_stacknode **a, t_stacknode **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->data != c && ft_find_place_b(*b, c) > 0)
			double_rotate(a, b);
		while ((*a)->data != c)
			reverse_rotate(a);
		while (ft_find_place_b(*b, c) > 0)
			reverse_rotate_b(b);
		push_b(a, b);
	}
	else
	{
		while ((*b)->data != c && ft_find_place_a(*a, c) > 0)
			double_rotate(a, b);
		while ((*b)->data != c)
			reverse_rotate_b(b);
		while (ft_find_place_a(*a, c) > 0)
			rotate(a);
		push_a(a, b);
	}
	return (-1);
}
