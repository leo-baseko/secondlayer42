/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:38:07 by ldrieske          #+#    #+#             */
/*   Updated: 2023/06/23 14:37:17 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	mechanicalturk(t_stacknode **stack_a, t_stacknode **stack_b)
{
	firstaction(stack_a, stack_b);
	secondaction(stack_a, stack_b);
	thirdaction(stack_a);
	fourthaction(stack_a, stack_b);
	finalaction(stack_a);
}

static int	doubles_av(char **strings, int size)
{
	int	i;
	int	j;
	int	k;
	int	duplicates;

	i = 0;
	j = 0;
	duplicates = 0;
	while (i < size - 1 && !duplicates)
	{
		j = i + 1;
		while (j < size && !duplicates)
		{
			k = 0;
			while (strings[i][k] != '\0' && strings[j][k] != '\0'
				&& strings[i][k] == strings[j][k])
				k++;
			if (strings[i][k] == strings[j][k])
				duplicates = 1;
			j++;
		}
		i++;
	}
	return (duplicates);
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
	if (j == 1 && is_valnum(av[1]))
		return (0);
	if (checknononsense(++av) == 0 || j < 2
		|| checknononsense(av) == -1 || doubles_av(av, j) > 0)
		ohnoerror(&stack, &stackb);
	while (i++ < j)
		push(&stack, ft_atoi(*av++));
	if (ft_checksorted(stack))
		return (0);
	if (j >= 5)
		mechanicalturk(&stack, &stackb);
	else
		hardcodehenry(j, &stack, &stackb);
	freestack(&stack);
	freestack(&stackb);
	return (0);
}
