/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:38:07 by ldrieske          #+#    #+#             */
/*   Updated: 2023/06/14 00:32:08 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static void	ohnoerror()
{
	write(2, "Error\n", 6);
	exit(0);
}


/*
 * checknononsense (pas de foutaises) 
 * 
 * check if theres doubles and non numerical values
 * Returns 1 if everything is good
 * Returns 0 if u fucked up
*/
static int	checknononsense(char **av)
{
	int	i;
	int	value;

	i = 1;
	if (!av[1])
		return (0);
	value = ft_atoi(av[i]);
	while (av[i])
	{
		if (value >= 2147483647 || value <= -2147483648)
			return (0);
		value = ft_atoi(av[i++]);
	}
	return (1);
}

int	main(int ac, char **av)
{
	int			i;
	int			j;
	t_stacknode	*stack;
	t_stacknode	*stackb;

	stack = NULL;
	stackb = NULL;
	i = 0;
	j = ac - 1;
	ft_printf("arguments : %d\n", ac);
	if (checknononsense(++av) == 0 || ac == 2)
		ohnoerror();
	while (i < j)
	{
		push(&stack, ft_atoi(*av));
		av++;
		i++;
	}
	ft_printf("Stack A : \n");
	printstackdata(stack);
	ft_printf("premiere action : \n");
	firstaction(&stack, &stackb);
	printstackdata(stackb);

	ft_printf("Seconde action : \n");
	secondaction(&stack, &stackb);
	ft_printf("Stack A : \n");
	printstackdata(stack);
	ft_printf("\nStack B : \n");
	printstackdata(stackb);
	// rotate(&stack);
	// printstackdata(stack);
	// reverse_rotate(&stack);
	// printstackdata(stack);
	// rotate(&stack);
	// printstackdata(stack);
	// swap(&stack);
	// printstackdata(stack);
	// swap(&stack);
	// printstackdata(stack);
	freestack(&stack);
	freestack(&stackb);
	return (0);
}
