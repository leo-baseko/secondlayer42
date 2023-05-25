/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:37:02 by ldrieske          #+#    #+#             */
/*   Updated: 2022/10/03 15:39:00 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* ft_isascii
*
* Checks if the value a is in the ASCII table
* Returns 1 if it is
*/

int	ft_isascii(int a)
{
	if (a >= 0 && a <= 127)
		return (1);
	return (0);
}
