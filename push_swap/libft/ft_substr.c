/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:14:40 by ldrieske          #+#    #+#             */
/*   Updated: 2022/11/18 14:19:27 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * ft_substr
 * 
 * char const *s : initial String
 * unsigned int start : index of start
 * size_t len : length of the new String
 * 
 * Allocates and returns a substring from the string s beginning 
 * at index start and of maximum size len
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;
	size_t	size;

	i = 0;
	size = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s) || len == 0 || ft_strlen(s) == 0)
		return (res = ft_calloc(sizeof(char), 1));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s) - start;
	while (s[size] && size < len && start < ft_strlen(s))
		size++;
	res = malloc(sizeof(char) * size + 1);
	if (!res)
		return (NULL);
	while (size != 0 && s[start])
	{
		res[i] = (char)s[start++];
		size--;
		i++;
	}
	res[i] = '\0';
	return (res);
}
