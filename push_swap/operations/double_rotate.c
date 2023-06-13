/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:33:57 by ldrieske          #+#    #+#             */
/*   Updated: 2023/06/13 21:36:43 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	double_rotate(t_stacknode **stack_a, t_stacknode **stack_b)
{
	t_stacknode	*lastnode;

	lastnode = *stack_a;
	if (*stack_a == NULL || (*stack_a)->next == NULL
		|| *stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	while (lastnode->next != NULL)
		lastnode = lastnode->next;
	lastnode->next = *stack_a;
	*stack_a = (*stack_a)->next;
	lastnode->next->next = NULL;
	lastnode = *stack_b;
	while (lastnode->next != NULL)
	lastnode = lastnode->next;
	lastnode->next = *stack_b;
	*stack_b = (*stack_b)->next;
	lastnode->next->next = NULL;
	ft_printf("rr\n");
}

static void	rrr_requirement(t_stacknode **stack_a, t_stacknode **stack_b)
{
	t_stacknode	*last_a;
	t_stacknode	*last_b;
	t_stacknode	*prev_a;
	t_stacknode	*prev_b;

	last_a = *stack_a;
	last_b = *stack_b;
	prev_a = NULL;
	prev_b = NULL;
	while (last_a->next != NULL)
	{
		prev_a = last_a;
		last_a = last_a->next;
	}
	while (last_b->next != NULL)
	{
		prev_b = last_b;
		last_b = last_b->next;
	}
	last_a->next = *stack_a;
	*stack_a = last_a;
	prev_a->next = NULL;
	last_b->next = *stack_b;
	*stack_b = last_b;
	prev_b->next = NULL;
}

void	double_reverse_rotate(t_stacknode **stack_a, t_stacknode **stack_b)
{
	t_stacknode	*last_a;
	t_stacknode	*last_b;
	t_stacknode	*prev_a;
	t_stacknode	*prev_b;

	last_a = *stack_a;
	last_b = *stack_b;
	prev_a = NULL;
	prev_b = NULL;
	if (last_a == NULL || last_a->next == NULL
		|| last_b == NULL || last_b->next == NULL)
		return ;
	rrr_requirement(stack_a, stack_b);
	ft_printf("rrr\n");
}
