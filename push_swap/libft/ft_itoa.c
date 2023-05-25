/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:09:17 by ldrieske          #+#    #+#             */
/*   Updated: 2022/11/17 15:21:01 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbr_char(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

/*
 * ft_itoa 
 * 
 * int n : the Integer we want as a String
 * 
 * Returns a String representing the Integer received as an argument
*/

char	*ft_itoa(int n)
{
	size_t		i;
	long int	j;
	char		*nbr;

	j = n;
	i = nbr_char(j);
	nbr = malloc(sizeof(char) * (i + 1));
	if (!nbr)
		return (0);
	nbr[i--] = '\0';
	if (j == 0)
		nbr[0] = '0';
	if (j < 0)
	{
		nbr[0] = '-';
		j *= -1;
	}
	while (j > 0)
	{
		nbr[i--] = j % 10 + '0';
		j /= 10;
	}
	return (nbr);
}
