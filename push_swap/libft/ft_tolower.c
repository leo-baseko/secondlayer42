/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:52:17 by ldrieske          #+#    #+#             */
/*   Updated: 2022/11/17 15:14:28 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * ft_tolower
 *
 * Change the value of a to his lowercase equivalent
*/

int	ft_tolower(int a)
{
	if (a >= 'A' && a <= 'Z')
		return (a += 32);
	return (a);
}
