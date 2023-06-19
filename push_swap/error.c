/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:29:58 by ldrieske          #+#    #+#             */
/*   Updated: 2023/06/19 16:28:40 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_stack(t_stacknode *stack)
{
	t_stacknode	*current;
	t_stacknode	*next;

	current = stack;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

void	ohnoerror(t_stacknode **stack_a, t_stacknode **stack_b)
{
	if (stack_a)
		free_stack(*stack_a);
	if (stack_b)
		free_stack(*stack_b);
	write(2, "Error\n", 6);
	exit(0);
}

static int	is_only_digits(char c)
{
	if (c == '-')
		return (1);
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/*
 * 
 * 
*/
int	is_valnum(char *str)
{
	int		i;
	long	num;

	i = 0;
	num = ft_atoi(str);
	if (str[0] == '-')
		i = 1;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (!is_only_digits(str[i]))
			return (0);
		i++;
	}
	if (i == 1 && str[0] == '-')
		return (0);
	if (num < -2147483648 || num > 2147483647)
		return (0);
	return (1);
}

/*
 * checknononsense (pas de foutaises) 
 * 
 * check if non numerical values
 * Returns 1 if everything is good
 * Returns 0 if u fucked up
*/
int	checknononsense(char **av)
{
	int	i;
	int	value;

	i = 0;
	while (av[i])
		if (!is_valnum(av[i++]))
			return (0);
	i = 1;
	value = ft_atoi(av[i]);
	while (av[i])
	{
		if (value >= 2147483647 || value <= -2147483648)
			return (0);
		value = ft_atoi(av[i++]);
	}
	return (1);
}
