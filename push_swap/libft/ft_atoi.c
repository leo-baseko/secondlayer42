/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drieske <drieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 15:14:32 by drieske          #+#    #+#             */
/*   Updated: 2022/11/17 11:01:10 by drieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * ft_atoi
 * 
 * const char *str : the String
 * 
 * Takes a String in parameter and returns only the numerical value
 * as an Integer
*/

int	ft_atoi(const char *str)
{
	int			i;
	int			n;
	long int	res;
	long int	temp;

	i = 0;
	res = 0;
	temp = 0;
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
		if (res < temp && n == -1)
			return (0);
		if (res < temp && n == 1)
			return (-1);
		temp = res;
	}
	return (n * (int)res);
}
