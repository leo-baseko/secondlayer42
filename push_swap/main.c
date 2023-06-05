/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:38:07 by ldrieske          #+#    #+#             */
/*   Updated: 2023/06/05 18:21:23 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	printf("%d pushed to stack\n", data);
}

/*
 * pop
 * 
 * StackNode **root : 
*/
int	pop(t_stacknode **root)
{
	struct s_stacknode	*temp;
	int					popped;

	if (isempty(*root))
		return (INT_MIN);
	temp = *root;
	*root = (*root)->next;
	popped = temp->data;
	free(temp);
	return (popped);
}

/*
 * peek
 * 
 * StackNode *root : 
*/
int	peek(t_stacknode *root)
{
	if (isempty(root))
		return (INT_MIN);
	return (root->data);
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

/*
 * checknononsense (pas de foutaises) 
 * 
 * check if theres doubles and non numerical values
 * Returns 1 if everything is good
 * Returns 0 if u fucked up
*/
static int checknononsense(char **av, int j)
{
	int	i;

	i = 1;
	if (av[1] == NULL)
		return (0);
	while (i < j)
	{
		if (!ft_atoi(av[i++]))
			return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	int			i;
	int			j;
	t_stacknode	*stack;

	stack = NULL;
	i = 0;
	j = ac - 1;
	ft_printf("arguments : %d\n", ac);
	av++;
	if (!checknononsense(av, j))
	{
		ft_printf("Error\n");
		return (0);
	}
	while(i < j)
	{
		push(&stack, ft_atoi(*av));
		av++;
		i++;
	}
	ft_printf("Données de la liste chainée : \n");
	printstackdata(stack);
	rotate(&stack);
	printstackdata(stack);
	reverse_rotate(&stack);
	printstackdata(stack);
	rotate(&stack);
	printstackdata(stack);
	swap(&stack);
	printstackdata(stack);
	swap(&stack);
	printstackdata(stack);
	freestack(&stack);
	return (0);
}
