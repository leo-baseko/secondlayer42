/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:14:49 by ldrieske          #+#    #+#             */
/*   Updated: 2023/06/13 13:41:10 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_a(t_stacknode **stack_a, t_stacknode **stack_b)
{
	t_stacknode	*top_b;

	top_b = *stack_b;
	if (*stack_b == NULL)
		return ;
	*stack_a = (*stack_a)->next;
	top_b->next = *stack_a;
	*stack_b = top_b;
	ft_printf("pa\n");
}

void	push_b(t_stacknode **stack_a, t_stacknode **stack_b)
{
	t_stacknode	*top_a;

	top_a = *stack_a;
	if (*stack_a == NULL)
		return ;
	*stack_a = (*stack_a)->next;
	top_a->next = *stack_b;
	*stack_b = top_a;
	ft_printf("pb\n");
}
