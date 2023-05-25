/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:23:09 by ldrieske          #+#    #+#             */
/*   Updated: 2022/10/03 15:36:36 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* ft_isalnum
*
* Checks if the value a is alphanumerical
* Returns 1 if it is
*/

int	ft_isalnum(int a)
{
	if (a >= 48 && a <= 57)
		return (1);
	if ((a >= 65 && a <= 90) || (a >= 97 && a <= 122))
		return (1);
	return (0);
}
