/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 11:28:56 by ldrieske          #+#    #+#             */
/*   Updated: 2022/11/17 12:29:00 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * ft_memcmp
 * 
 * Pretty similar to strncmp
 * Gives the n bytes difference between s1 and s2
 * Returns 0 is there's no difference
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*c1;
	const unsigned char	*c2;
	int					i;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	i = 0;
	while (n > 0)
	{
		if (c1[i] != c2[i])
			break ;
		i++;
		n--;
	}
	if (n == 0)
		return (0);
	return (c1[i] - c2[i]);
}
