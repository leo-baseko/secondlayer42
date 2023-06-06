/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mechanicalturk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:07:15 by ldrieske          #+#    #+#             */
/*   Updated: 2023/06/06 19:51:12 by ldrieske         ###   ########.fr       */
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
	push_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
}
/*
 * secondaction
 * 
 * search the cheapest number to push to the B stack
*/
void	secondaction()
{
	
}

/*
 * thirdaction
 * 
 * put the last 3 elements of the A stack in order
*/
void	thirdaction()
{
	
}

/*
 * fourthaction
 * 
 * put every elements of the B stack in the A stack
*/
void	fourthaction()
{
	
}

/*
 * finalaction
 * 
 * put the minimum on top of the A stack
 * Everythings should be working now !
*/
void	finalaction()
{

}
