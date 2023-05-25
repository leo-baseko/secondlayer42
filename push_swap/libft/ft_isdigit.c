/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:10:20 by ldrieske          #+#    #+#             */
/*   Updated: 2022/10/03 13:12:54 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* ft_isdigit
*
* Checks if the value of the Integer a is indeed a digit
* (Must use a chr or the value of the character in the ASCII table)
* Returns 1 if it is
*/

int	ft_isdigit(int a)
{
	if (a >= 48 && a <= 57)
		return (1);
	return (0);
}
