/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mechanicalturk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:07:15 by ldrieske          #+#    #+#             */
/*   Updated: 2023/06/16 23:22:27 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
 * firstaction
 * 
 * push 2 numbers in the B stack
*/
void	firstaction(t_stacknode **stack_a, t_stacknode **stack_b)
{
	push_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
}

/*
 * secondaction
 * 
 * search the cheapest number to push to the B stack until
 * we hit 3 numbers in the A stack
*/
void	secondaction(t_stacknode **stack_a, t_stacknode **stack_b)
{
	int			i;
	t_stacknode	*tmp;

	while (!ft_checksorted(*stack_a) && lstsize(*stack_a) > 3)
	{
		tmp = *stack_a;
		i = ft_rotate_type_ab(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == ft_case_rarb(*stack_a, *stack_b, tmp->data))
				i = ft_apply_rarb(stack_a, stack_b, tmp->data, 'a');
			else if (i == ft_case_rrarrb(*stack_a, *stack_b, tmp->data))
				i = ft_apply_rrarrb(stack_a, stack_b, tmp->data, 'a');
			else if (i == ft_case_rarrb(*stack_a, *stack_b, tmp->data))
				i = ft_apply_rarrb(stack_a, stack_b, tmp->data, 'a');
			else if (i == ft_case_rrarb(*stack_a, *stack_b, tmp->data))
				i = ft_apply_rrarb(stack_a, stack_b, tmp->data, 'a');
			else
				tmp = tmp->next;
		}
	}
}

/*
 * thirdaction
 * 
 * put the last 3 elements of the A stack in order
*/
void	thirdaction(t_stacknode **stack_a)
{
	if (ft_min(*stack_a) == (*stack_a)->data)
	{
		reverse_rotate(stack_a);
		swap(stack_a);
	}
	else if (ft_max(*stack_a) == (*stack_a)->data)
	{
		rotate(stack_a);
		if (!ft_checksorted(*stack_a))
			swap(stack_a);
	}
	else
	{
		if (ft_find_index(*stack_a, ft_max(*stack_a)) == 1)
			reverse_rotate(stack_a);
		else
			swap(stack_a);
	}
}

/*
 * fourthaction
 * 
 * put every elements of the B stack in the A stack
*/
void	fourthaction(t_stacknode **stack_a, t_stacknode **stack_b)
{
	int			i;
	t_stacknode	*tmp;

	while (*stack_b)
	{
		tmp = *stack_b;
		i = ft_rotate_type_ba(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == ft_case_rarb_a(*stack_a, *stack_b, tmp->data))
				i = ft_apply_rarb(stack_a, stack_b, tmp->data, 'b');
			else if (i == ft_case_rarrb_a(*stack_a, *stack_b, tmp->data))
				i = ft_apply_rarrb(stack_a, stack_b, tmp->data, 'b');
			else if (i == ft_case_rrarrb_a(*stack_a, *stack_b, tmp->data))
				i = ft_apply_rrarrb(stack_a, stack_b, tmp->data, 'b');
			else if (i == ft_case_rrarb_a(*stack_a, *stack_b, tmp->data))
				i = ft_apply_rrarb(stack_a, stack_b, tmp->data, 'b');
			else
				tmp = tmp->next;
		}
	}
}

/*
 * finalaction
 * 
 * put the minimum on top of the A stack
 * Everythings should be working now !
*/
void	finalaction(t_stacknode **stack_a)
{
	int	i;

	i = ft_find_index(*stack_a, ft_min(*stack_a));
	if (i < lstsize(*stack_a) - i)
	{
		while ((*stack_a)->data != ft_min(*stack_a))
			rotate(stack_a);
	}
	else
	{
		while ((*stack_a)->data != ft_min(*stack_a))
			reverse_rotate(stack_a);
	}	
}
