/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 15:48:12 by ldrieske          #+#    #+#             */
/*   Updated: 2022/11/17 12:45:07 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * ft_strdup
 *
 * Allocates sufficient memory (malloc) for a copy of s1
 * Returns a pointer of the copy
*/

char	*ft_strdup(const char *s1)
{
	char	*a;
	int		j;
	int		len;

	j = 0;
	len = ft_strlen((char *)s1);
	a = malloc(sizeof(char) * (len + 1));
	if (!a)
		return (0);
	while (s1[j])
	{
		a[j] = s1[j];
		j++;
	}
	a[j] = '\0';
	return (a);
}
