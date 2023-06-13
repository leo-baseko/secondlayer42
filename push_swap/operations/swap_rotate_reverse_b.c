/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rotate_reverse_b.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:32:22 by ldrieske          #+#    #+#             */
/*   Updated: 2023/06/13 22:12:51 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
 * swap_b
 *
 * t_stacknode **stack : stack b
 * swap the first 2 elements of the b stack
 * do nothing if the stack is empty or don't have enough elements to swap
*/
void	swap_b(t_stacknode **stack)
{
	t_stacknode	*firstnode;
	t_stacknode	*secondnode;

	if ((*stack) == NULL || (*stack)->next == NULL)
		return ;
	firstnode = (*stack);
	secondnode = (*stack)->next;
	firstnode->next = secondnode->next;
	secondnode->next = firstnode;
	(*stack) = secondnode;
	ft_printf("sb\n");
}

void	rotate_b(t_stacknode **stack)
{
	t_stacknode	*lastnode;

	lastnode = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	while (lastnode->next != NULL)
		lastnode = lastnode->next;
	lastnode->next = *stack;
	*stack = (*stack)->next;
	lastnode->next->next = NULL;
	ft_printf("rb\n");
}

void	reverse_rotate_b(t_stacknode **stack)
{
	t_stacknode	*lastnode;
	t_stacknode	*prevnode;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	lastnode = *stack;
	prevnode = NULL;
	while (lastnode->next != NULL)
	{
		prevnode = lastnode;
		lastnode = lastnode->next;
	}
	lastnode->next = *stack;
	*stack = lastnode;
	prevnode->next = NULL;
	ft_printf("rrb\n");
}
