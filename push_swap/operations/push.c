/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:14:49 by ldrieske          #+#    #+#             */
/*   Updated: 2023/06/06 19:36:39 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_a(t_stacknode **stack_a, t_stacknode **stack_b)
{
	t_stacknode	*top_a;

	top_a = *stack_a;  // Pointeur vers le premier nœud de stack_a
	if (*stack_a == NULL)
        return;  // Rien à déplacer, stack_a est vide
    *stack_a = (*stack_a)->next;  // Mettre à jour stack_a pour supprimer le premier nœud
    top_a->next = *stack_b;  // Lier le premier nœud de stack_a avec le premier nœud de stack_b
    *stack_b = top_a;  // Mettre à jour stack_b pour pointer vers le nouveau premier nœud
    ft_printf("pa\n");
}

void	push_b()
{
	ft_printf("pb\n");
}