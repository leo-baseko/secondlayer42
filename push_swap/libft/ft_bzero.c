/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:32:42 by ldrieske          #+#    #+#             */
/*   Updated: 2022/11/18 14:26:01 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* ft_bzero
*
* Takes a String value and put n times '\0' in it
*/

void	ft_bzero(void *a, size_t n)
{
	ft_memset(a, '\0', n);
}
