/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rotate_reverse.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 23:01:02 by ldrieske          #+#    #+#             */
/*   Updated: 2023/06/05 15:39:00 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
 * swap
 *
 * t_stacknode **stack : 
 * swap les deux premiers elements de la stack a
 * ne fait rien si stack est vide
*/
void	swap(t_stacknode **stack)
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
	ft_printf("sa\n");
}

void	rotate(t_stacknode **stack)
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
	ft_printf("ra\n");
}

void	reverse_rotate(t_stacknode **stack)
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
	ft_printf("rra\n");
}
