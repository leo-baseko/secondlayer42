/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:33:51 by ldrieske          #+#    #+#             */
/*   Updated: 2022/11/17 12:29:30 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * ft_memcpy
 *
 * Copies n values of src into dst
*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	void	*str;

	str = dst;
	i = 0;
	if (src == dst)
		return (NULL);
	while (i < n)
	{
		*(char *)dst = *(char *)src;
		dst++;
		src++;
		i++;
	}
	return (str);
}
