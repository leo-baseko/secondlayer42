/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mechanicalturk_utils4.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:29:31 by ldrieske          #+#    #+#             */
/*   Updated: 2023/06/14 00:08:20 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
 * ft_apply_rrarrb
 * 
 * t_stacknode a : stack a
 * t_stacknode b : stack b
 * int c : value of the number
 * char s : character we use to know if we're talking about the stack a or b
 * 
 * Rotate both stack_a and stack_b in the reverse_rotate
 * direction as required amount.
*/
int	ft_apply_rrarrb(t_stacknode **a, t_stacknode **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->data != c && ft_find_place_b(*b, c) > 0)
			double_reverse_rotate(a, b);
		while ((*a)->data != c)
			reverse_rotate(a);
		while (ft_find_place_b(*b, c) > 0)
			reverse_rotate_b(b);
		push_b(a, b);
	}
	else
	{
		while ((*b)->data != c && ft_find_place_a(*a, c) > 0)
			double_reverse_rotate(a, b);
		while ((*b)->data != c)
			reverse_rotate_b(b);
		while (ft_find_place_a(*a, c) > 0)
			reverse_rotate(a);
		push_a(a, b);
	}
	return (-1);
}

/*
 * ft_apply_rrarb
 * 
 * t_stacknode a : stack a
 * t_stacknode b : stack b
 * int c : value of the number
 * char s : character we use to know if we're talking about the stack a or b
 * 
 * Rotate both stack_a and stack_b in the reverse_rotate
 * direction as required amount.
*/
int	ft_apply_rrarb(t_stacknode **a, t_stacknode **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->data != c)
			reverse_rotate(a);
		while (ft_find_place_b(*b, c) > 0)
			reverse_rotate_b(b);
		push_b(a, b);
	}
	else
	{
		while (ft_find_place_a(*a, c) > 0)
			reverse_rotate(a);
		while ((*b)->data != c)
			reverse_rotate_b(b);
		push_a(a, b);
	}
	return (-1);
}

/*
 * ft_apply_rarrb
 * 
 * t_stacknode a : stack a
 * t_stacknode b : stack b
 * int c : value of the number
 * char s : character we use to know if we're talking about the stack a or b
 * 
 * Rotate both stack_a and stack_a in the reverse_rotate
 * direction as required amount.
*/
int	ft_apply_rarrb(t_stacknode **a, t_stacknode **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->data != c)
			rotate(a);
		while (ft_find_place_b(*b, c) > 0)
			reverse_rotate_b(b);
		push_b(a, b);
	}
	else
	{
		while (ft_find_place_a(*a, c) > 0)
			rotate(a);
		while ((*b)->data != c)
			reverse_rotate_b(b);
		push_a(a, b);
	}
	return (-1);
}

/*
 * ft_checksorted
 * 
 * t_stacknode stack : the stack (who would have thought ?)
 * 
 * Checks if the stack is sorted
*/
int	ft_checksorted(t_stacknode *stack)
{
	int	i;

	i = stack->data;
	while (stack)
	{
		if (i > stack->data)
			return (0);
		i = stack->data;
		stack = stack->next;
	}
	return (1);
}

/*
 * ft_find_index
 * 
 * t_stacknode a : the stack (who would have thought ?)
 * int data : the number in the stack
 * 
 * Checks the index of a number in the stack
*/
int	ft_find_index(t_stacknode *a, int data)
{
	int		i;

	i = 0;
	while (a->data != data)
	{
		i++;
		a = a->next;
	}
	a->index = 0;
	return (i);
}
