/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rotate_reverse.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 23:01:02 by ldrieske          #+#    #+#             */
/*   Updated: 2023/06/03 23:25:40 by ldrieske         ###   ########.fr       */
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
		return;//Pas assez d'éléments dans la pile pour effectuer un échange
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
	t_stacknode	*secondlastnode;

	if (*stack == NULL || (*stack)->next == NULL)
		return;  // La pile est vide ou a un seul élément, pas besoin de décaler
	// Trouver le dernier et l'avant-dernier nœud de la pile
	lastnode = *stack;
	secondlastnode = NULL;
	while (lastnode->next != NULL)
	{
		secondlastnode = lastnode;
		lastnode = lastnode->next;
	}
	// Décaler les nœuds vers le haut
	lastnode->next = *stack;
	secondlastnode->next = NULL;
	*stack = lastnode;
	ft_printf("ra\n");
}

void	reverse_rotate(t_stacknode **stack)
{
	t_stacknode	*lastnode;
	t_stacknode	*prevnode;

	if (*stack == NULL || (*stack)->next == NULL)
		return;  // La pile est vide ou a un seul élément, pas besoin de décaler
	lastnode = *stack;
	prevnode = NULL;
	// Trouver le dernier nœud de la pile
	while (lastnode->next != NULL) 
	{
		prevnode = lastnode;
		lastnode = lastnode->next;
	}
	// Décaler les nœuds vers le bas
	lastnode->next = *stack;
	*stack = lastnode;
	prevnode->next = NULL;
	ft_printf("rra\n");
}
