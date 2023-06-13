/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mechanicalturk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:07:15 by ldrieske          #+#    #+#             */
/*   Updated: 2023/06/13 21:51:28 by ldrieske         ###   ########.fr       */
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
/*void	thirdaction()
{
	
}*/

/*
 * fourthaction
 * 
 * put every elements of the B stack in the A stack
*/
/*void	fourthaction()
{
	
}*/

/*
 * finalaction
 * 
 * put the minimum on top of the A stack
 * Everythings should be working now !
*/
/*void	finalaction()
{

}*/
