/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:38:07 by ldrieske          #+#    #+#             */
/*   Updated: 2023/06/03 20:19:03 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct StackNode	*newNode(int data)
{
	struct StackNode	*stackNode;

	stackNode = (struct StackNode*)malloc(sizeof(struct StackNode));
	stackNode->data = data;
	stackNode->next = NULL;
	return (stackNode);
}

int	isEmpty(struct StackNode *root)
{
	return (!root);
}

void	push(struct StackNode **root, int data)
{
	struct StackNode* stackNode = newNode(data);
	stackNode->next = *root;
	*root = stackNode;
	printf("%d pushed to stack\n", data);
}

int	pop(struct StackNode **root)
{
	if (isEmpty(*root))
		return INT_MIN;
	struct StackNode* temp = *root;
	*root = (*root)->next;
	int popped = temp->data;
	free(temp);

	return (popped);
}

int	peek(struct StackNode *root)
{
	if (isEmpty(root))
		return INT_MIN;
	return (root->data);
}

/*
 * swap les deux premiers elements de la stack a
 * ne fait rien si stack est vide
*/
void	swap_a(struct StackNode **stack)
{
	if ((*stack) == NULL || (*stack)->next == NULL)
		return;  // Pas assez d'éléments dans la pile pour effectuer un échange

	ft_printf("sa\n");
	StackNode *firstNode = (*stack);
	StackNode *secondNode = (*stack)->next;

	firstNode->next = secondNode->next;
	secondNode->next = firstNode;
	(*stack) = secondNode;
}

void	freeStack(StackNode **stack)
{
	StackNode *currentNode;

	currentNode = *stack;
	while (currentNode != NULL) {
		StackNode* nextNode = currentNode->next;
		free(currentNode);
		currentNode = nextNode;
	}
	*stack = NULL;
}

void	printStackData(const StackNode *stack)
{
	const StackNode* currentNode = stack;
	while (currentNode != NULL)
	{
		ft_printf("%d ", currentNode->data);
		currentNode = currentNode->next;
	}
	ft_printf("\n");
}

int	main()
{
	StackNode *stack;
	
	stack = NULL;
	push(&stack, 5);
	push(&stack, 7);
	push(&stack, 9);
	push(&stack, 4);
	push(&stack, 6);
	push(&stack, 3);
	// Lire les données de la liste chaînée
	ft_printf("Donnees de la liste chainee : ");
	printStackData(stack);
	swap_a(&stack);
	printStackData(stack);
	// Libérer la mémoire allouée pour la liste chaînée
	freeStack(&stack);
	return (0);
}
