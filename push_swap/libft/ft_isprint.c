/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:39:16 by ldrieske          #+#    #+#             */
/*   Updated: 2022/10/03 15:40:55 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* ft_isprint
*
* Checks if the value of the Integer a is indeed printable
* (Must use a chr or the value of the character in the ASCII table)
* Returns 1 if it is
*/

int	ft_isprint(int a)
{
	if (a >= 32 && a <= 126)
		return (1);
	return (0);
}
