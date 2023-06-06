/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 19:59:42 by ldrieske          #+#    #+#             */
/*   Updated: 2023/06/06 19:44:41 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include "./libftprintf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <stdarg.h>

typedef struct s_stacknode {
	int					data;
	struct s_stacknode	*next;
}	t_stacknode;

void				swap(t_stacknode **stack);
void				rotate(t_stacknode **stack);
void				reverse_rotate(t_stacknode **stack);
struct s_stacknode	*newnode(int data);
int					isempty(t_stacknode *root);
void				push(t_stacknode **root, int data);
int					pop(t_stacknode **root);
int					peek(t_stacknode *root);
void				freestack(t_stacknode **stack);
void				printstackdata(const t_stacknode *stack);
void				push_a(t_stacknode **stack_a, t_stacknode **stack_b);

//Fonctions mechanical turk
void				firstaction(t_stacknode **stack_a, t_stacknode **stack_b);
#endif