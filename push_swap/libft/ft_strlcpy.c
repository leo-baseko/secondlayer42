/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:45:54 by ldrieske          #+#    #+#             */
/*   Updated: 2022/11/17 12:31:11 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * ft_strlcpy
 *
 * Copies and concatenates Strings with the same input parameters
 * It does less errors than strncpy and strncat
 * Returns the total length of the String it tried to create (length of src)
*/

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	char		*d;
	const char	*s;
	size_t		i;
	size_t		n;

	d = dst;
	s = src;
	n = size - 1;
	i = 0;
	if (size == 0)
		return (ft_strlen((char *)src));
	while (i < n && *s)
	{
		*d = *s;
		d++;
		s++;
		i++;
	}
	*d = '\0';
	return (ft_strlen((char *)src));
}
