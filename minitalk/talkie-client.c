/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   talkie-client.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:44:59 by ldrieske          #+#    #+#             */
/*   Updated: 2023/08/05 14:54:21 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
 * Checklist client : 
 * 		Takes the PID of the server to send to and the message
 * 		Encrypt the message (bits)
 * 		Send the message
 * 		Create a stop condition so the server knows the message ended
*/

int	dec_to_bin(int dec)
{
	int	bin;
	int	bit;

	bin = 0;
	bit = 1;
	while (dec > 0)
	{
		if (dec % 2 == 1)
			bin += bit;
		dec /= 2;
		bit *= 10;
	}
	return (bin);
}

void	encrypt_mess(char *message)
{
	int i;

	i = 0;
	while (message[i])
	{
		i++;
	}
}

int	main(int ac, char **av)
{
	//int		pid;
	printf("client : coucou\n");
	if (ac != 3)
		return (0);
	//pid = av[1];
	//encrypt_mess(av[2]);
	int test = decimalToBinary('l');
	printf("parametre 2 : %s\n", av[2]);
	printf("test en binaire : %d\n", test);
	return (0);
}
