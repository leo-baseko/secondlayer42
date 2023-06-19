/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardcodehenry.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:56:08 by ldrieske          #+#    #+#             */
/*   Updated: 2023/06/19 14:34:35 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_two(t_stacknode **stack_a)
{
	if (!ft_checksorted(*stack_a))
		rotate(stack_a);
}

void	sort_three(t_stacknode *stack_a)
{
	long	first;
	long	second;
	long	third;

	first = stack_a->data;
	second = stack_a->next->data;
	third = stack_a->next->next->data;
	if (first < second && first < third && second > third)
	{
		swap(&stack_a);
		rotate(&stack_a);
	}
	else if (first > second && first < third && second < third)
		swap(&stack_a);
	else if (first < second && first > third && second > third)
		reverse_rotate(&stack_a);
	else if (first > second && first > third && second < third)
		rotate(&stack_a);
	else if (first > second && first > third && second > third)
	{
		swap(&stack_a);
		reverse_rotate(&stack_a);
	}
}

static void	sort_four(t_stacknode *stack_a, t_stacknode *stack_b)
{
	while (stack_a->data != ft_min(stack_a))
		rotate(&stack_a);
	push_b(&stack_a, &stack_b);
	sort_three(stack_a);
	push_a(&stack_a, &stack_b);
}

static void	sort_five(t_stacknode *stack_a, t_stacknode *stack_b)
{
	int		i;

	i = 0;
	while (i < 2)
	{
		while (stack_a->next->index != 0 && stack_a->next->index != 1)
			rotate(&stack_a);
		push_b(&stack_a, &stack_b);
		i++;
	}
	sort_three(stack_a);
	if (ft_checksorted(stack_b))
		rotate_b(&stack_b);
	push_a(&stack_a, &stack_b);
	push_a(&stack_a, &stack_b);
}

void	hardcodehenry(int ac, t_stacknode **stack_a, t_stacknode **stack_b)
{
	if (ac == 2)
		sort_two(stack_a);
	if (ac == 3)
		sort_three(*stack_a);
	if (ac == 4)
		sort_four(*stack_a, *stack_b);
	if (ac == 5)
		sort_five(*stack_a, *stack_b);
}
