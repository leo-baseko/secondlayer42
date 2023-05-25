/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 23:23:56 by ldrieske          #+#    #+#             */
/*   Updated: 2022/11/17 15:09:41 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{	
	const unsigned char	*p;

	p = s;
	if (n == 0)
		return (NULL);
	while (n != 0)
	{
		if (*p++ == (unsigned char)c)
			return ((void *)(p - 1));
		n--;
	}
	return (NULL);
}
