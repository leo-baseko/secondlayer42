/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:29:16 by ldrieske          #+#    #+#             */
/*   Updated: 2023/06/13 22:16:24 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
 * newnode 
 * 
 * int data :
 * return 
*/
struct s_stacknode	*newnode(int data)
{
	struct s_stacknode	*stacknode;

	stacknode = malloc(sizeof(struct s_stacknode));
	stacknode->data = data;
	stacknode->next = NULL;
	return (stacknode);
}

/*
 * isempty
 * 
 * StackNode *root : 
*/
int	isempty(t_stacknode *root)
{
	return (!root);
}

/*
 * push
 * 
 * StackNode **root : 
 * int data : 
*/
void	push(t_stacknode **root, int data)
{
	struct s_stacknode	*stacknode;
	struct s_stacknode	*current;

	stacknode = newnode(data);
	if (*root == NULL)
		*root = stacknode;
	else
	{
		current = *root;
		while (current->next != NULL)
			current = current->next;
		current->next = stacknode;
	}
}

/*
 * freestack
 * 
 * StackNode **stack :
*/
void	freestack(t_stacknode **stack)
{
	t_stacknode	*currentnode;
	t_stacknode	*nextnode;

	currentnode = *stack;
	while (currentnode != NULL)
	{
		nextnode = currentnode->next;
		free(currentnode);
		currentnode = nextnode;
	}
	*stack = NULL;
}

/*
 * printstackdata
 * 
 * StackNode *stack : 
*/
void	printstackdata(const t_stacknode *stack)
{
	const t_stacknode	*currentnode;

	currentnode = stack;
	while (currentnode != NULL)
	{
		ft_printf("%d ", currentnode->data);
		currentnode = currentnode->next;
	}
	ft_printf("\n");
}
