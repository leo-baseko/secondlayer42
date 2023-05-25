/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 11:46:47 by ldrieske          #+#    #+#             */
/*   Updated: 2022/11/17 12:48:10 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * ft_strnstr
 *
 * Find the needle String in the haystack String at the len size
 * Returns a pointer of the result if it has been find
*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		if (haystack[i] == needle[0])
		{
			k = i;
			while (needle[j] != '\0' && haystack[k] == needle[j] && k < len)
			{
				j++;
				k++;
			}
			if (j == ft_strlen((char *)needle))
				return ((char *)haystack + i);
		}
		i++;
		j = 0;
	}
	return (0);
}
