/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:21:02 by ldrieske          #+#    #+#             */
/*   Updated: 2023/06/23 14:39:16 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_stack(t_stacknode *stack)
{
	t_stacknode	*current;
	t_stacknode	*next;

	current = stack;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

void	ohnoerror(t_stacknode **stack_a, t_stacknode **stack_b)
{
	if (stack_a)
		free_stack(*stack_a);
	if (stack_b)
		free_stack(*stack_b);
	write(2, "Error\n", 6);
	exit(0);
}
