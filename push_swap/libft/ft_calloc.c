/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 15:42:05 by ldrieske          #+#    #+#             */
/*   Updated: 2022/11/18 13:36:29 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* ft_calloc
*
* Takes the count and size in parameter to return a pointer of type void
* which can be cast into a pointer of any form
*/

void	*ft_calloc(size_t count, size_t size)
{
	void	*m;

	m = malloc(size * count);
	if (!m)
		return (NULL);
	ft_bzero(m, size * count);
	return (m);
}
