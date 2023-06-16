/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 19:59:42 by ldrieske          #+#    #+#             */
/*   Updated: 2023/06/16 23:11:42 by ldrieske         ###   ########.fr       */
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
	long				data;
	long				index;
	struct s_stacknode	*next;
	struct s_stacknode	*prev;
}	t_stacknode;

void				push_a(t_stacknode **stack_a, t_stacknode **stack_b);
void				push_b(t_stacknode **stack_a, t_stacknode **stack_b);
void				swap(t_stacknode **stack);
void				swap_b(t_stacknode **stack);
void				rotate(t_stacknode **stack);
void				rotate_b(t_stacknode **stack);
void				reverse_rotate(t_stacknode **stack);
void				reverse_rotate_b(t_stacknode **stack);
void				double_rotate(t_stacknode **stack_a, t_stacknode **stack_b);
void				double_reverse_rotate(
						t_stacknode **stack_a, t_stacknode **stack_b);
struct s_stacknode	*newnode(int data);
int					isempty(t_stacknode *root);
void				push(t_stacknode **root, int data);
int					pop(t_stacknode **root);
int					peek(t_stacknode *root);
void				freestack(t_stacknode **stack);
void				printstackdata(const t_stacknode *stack);
void				firstaction(t_stacknode **stack_a, t_stacknode **stack_b);
void				secondaction(t_stacknode **stack_a, t_stacknode **stack_b);
void				thirdaction(t_stacknode **stack_a);
void				fourthaction(t_stacknode **stack_a, t_stacknode **stack_b);
void				finalaction(t_stacknode **stack_a);

int					ft_rotate_type_ba(t_stacknode *a, t_stacknode *b);
int					ft_rotate_type_ab(t_stacknode *a, t_stacknode *b);
int					ft_case_rarb(t_stacknode *a, t_stacknode *b, int c);
int					ft_case_rrarrb(t_stacknode *a, t_stacknode *b, int c);
int					ft_case_rrarb(t_stacknode *a, t_stacknode *b, int c);
int					ft_case_rarrb(t_stacknode *a, t_stacknode *b, int c);
int					ft_apply_rarb(
						t_stacknode **a, t_stacknode **b, int c, char s);
int					ft_apply_rrarrb(
						t_stacknode **a, t_stacknode **b, int c, char s);
int					ft_apply_rrarb(
						t_stacknode **a, t_stacknode **b, int c, char s);
int					ft_apply_rarrb(
						t_stacknode **a, t_stacknode **b, int c, char s);
int					ft_case_rrarb_a(t_stacknode *a, t_stacknode *b, int c);
int					ft_case_rarrb_a(t_stacknode *a, t_stacknode *b, int c);
int					ft_case_rrarrb_a(t_stacknode *a, t_stacknode *b, int c);
int					ft_case_rarb_a(t_stacknode *a, t_stacknode *b, int c);
int					ft_checksorted(t_stacknode *stack_a);
int					ft_find_index(t_stacknode *a, int data);
int					ft_find_place_b(t_stacknode *stack_b, int nbr_push);
int					ft_find_place_a(t_stacknode *stack_a, int nbr_push);
t_stacknode			*lstlast(t_stacknode *lst);
int					lstsize(t_stacknode *lst);
int					ft_min(t_stacknode *a);
int					ft_max(t_stacknode *a);

#endif