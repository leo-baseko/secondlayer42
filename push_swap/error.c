/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:29:58 by ldrieske          #+#    #+#             */
/*   Updated: 2023/06/19 18:22:54 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_only_digits(char c)
{
	if (c == '-')
		return (1);
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static long	ft_atoi_push_swap(const char *str)
{
	int			i;
	int			n;
	long int	res;

	i = 0;
	res = 0;
	n = 1;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-')
		n *= -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i++] - '0';
		if ((res > 2147483647 && n == 1) || res > 2147483648)
			return (2147483648);
	}
	return (n * (int)res);
}

int	is_valnum(char *str)
{
	int		i;
	long	num;

	i = 0;
	num = ft_atoi_push_swap(str);
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
	if (num == 2147483648)
		return (0);
	return (1);
}

int	checknononsense(char **av)
{
	int		i;
	long	value;

	i = 0;
	while (av[i])
		if (!is_valnum(av[i++]))
			return (0);
	i = 1;
	value = ft_atoi_push_swap(av[i]);
	while (av[i])
	{
		if (value == 2147483648)
			return (0);
		value = ft_atoi_push_swap(av[i++]);
	}
	return (1);
}
