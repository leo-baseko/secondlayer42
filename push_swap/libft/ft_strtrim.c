/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 20:08:07 by ldrieske          #+#    #+#             */
/*   Updated: 2022/11/17 12:48:45 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * count how many set characters there is in the s1 debut
*/

static size_t	cbegin(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	test;
	size_t	res;

	i = 0;
	res = 0;
	while (s1[i])
	{
		j = 0;
		test = 0;
		while (j < ft_strlen(set))
		{
			if (s1[i] == set[j])
				test++;
			j++;
		}
		if (test > 0)
			res++;
		else if (test == 0)
			return (res);
		i++;
	}
	return (res);
}

/*
 * count how many set characters there is in the s1 last part
*/

static size_t	clast(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	test;
	size_t	res;

	i = ft_strlen(s1) - 1;
	res = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		test = 0;
		while (j < ft_strlen(set))
		{
			if (s1[i] == set[j])
				test++;
			j++;
		}
		if (test > 0)
			res++;
		else if (test == 0)
			return (res);
		i--;
	}
	return (res);
}

/*
 * ft_strtrim
 * 
 * char const *s1 : the String we want to trim
 * char const *set : the characters that will trim s1
 * 
 * Returns the s1 String without the characters of set at the
 * beginning and ending of the String
*/

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	i;
	size_t	j;
	size_t	begin;
	size_t	last;

	if (!s1 || !set)
		return (NULL);
	j = 0;
	begin = cbegin(s1, set);
	if (begin == ft_strlen(s1))
		return (res = ft_calloc(sizeof(char), 1));
	last = clast(s1, set);
	i = begin + last;
	if (ft_strlen(s1) < i)
		return (NULL);
	res = malloc(sizeof(char) * (ft_strlen(s1) - i) + 1);
	if (!res)
		return (NULL);
	i = begin;
	while (s1[i] && i < ft_strlen(s1) - last)
		res[j++] = (char)s1[i++];
	res[j] = '\0';
	return (res);
}
