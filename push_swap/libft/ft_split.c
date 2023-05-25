/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:32:54 by ldrieske          #+#    #+#             */
/*   Updated: 2022/11/18 14:47:52 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * words_count
 * 
 * const char *s : the String we want splitted
 * char sep : the separator we are using
 * 
 * Returns the number of words that we're going to display
 * Returns 0 if s[0] is NULL
*/

static int	words_count(const char *s, char c)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			while (s[i] && s[i] != c)
				i++;
			size++;
		}
	}
	return (size);
}

/*
 * word_len
 *
 * const char *s : the String we want to split
 * char c : the separator
 * int start : the starting position
 * 
 * Returns the length of the a word in s String at start position
*/

static int	word_len(const char *s, char c, int start)
{
	int	i;

	i = start;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i - start);
}

/*
 * free_return
 * 
 * char **tab : the whole table
 * 
 * Frees the memory inside table
 * Then it frees the whole table
*/

static char	**free_return(char **tab, int k)
{
	while (--k >= 0)
		free(tab[k]);
	free(tab);
	return (NULL);
}

/*
 * tosplit 
 * 
 * const char *s : the String we want to split 
 * char c : the separator
 * char **tab : the final product
 * 
 * Returns the table malloced properly and with the words in it
*/

char	**tosplit(const char *s, char c, char **tab)
{
	char	**res;
	int		i;
	int		j;
	int		k;

	res = tab;
	i = -1;
	k = 0;
	while (s[++i])
	{
		j = -1;
		if (s[i] != c)
		{
			res[k] = malloc(sizeof(char) * (word_len(s, c, i) + 1));
			if (!res[k])
				return (free_return(res, k));
			while (++j < word_len(s, c, i))
				res[k][j] = s[i + j];
			res[k++][j] = '\0';
			i += j - 1;
		}
	}
	res[k] = NULL;
	return (res);
}

/*
* ft_split
*
* char const *s : the String we want to split
* char c : the separator
*
* Allocates the memory of the characters table from the s characters chain
*/

char	**ft_split(char const *s, char c)
{
	char	**res;

	if (!s)
		return (0);
	res = malloc(sizeof(char *) * (words_count(s, c) + 1));
	if (!res)
		return (0);
	res = tosplit(s, c, res);
	return (res);
}
