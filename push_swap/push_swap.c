/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:46:32 by ldrieske          #+#    #+#             */
/*   Updated: 2023/05/23 15:47:50 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int stack[256];
int count = 0;

void push(int x)
{
	stack[count] = x;
	count++;
}

int pop()
{
	int res =stack[count - 1];
	count--;
	return res;
}

#include <stdio.h>
int	main(int ac, char *av[])
{
	push(1);
	push(2);
	push(3);
	push(5);

	int i;
	for (i = 0; i < 4; i++)
	{
		printf("%d", pop());
	}
}