/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   talkie-client.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:44:59 by ldrieske          #+#    #+#             */
/*   Updated: 2023/08/09 18:26:55 by ldrieske         ###   ########.fr       */
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
/*
 * eight_bits_value
 * 
 * Creates new char 
*/
char	*eight_bits_value(void)
{
	int		i;
	char	*newval;

	i = 0;
	newval = malloc(sizeof(char) * 9);
	if (!newval)
		return (0);
	while (i < 8)
		newval[i++] = '0';
	newval[i] = '\0';
	return (newval);
}
/*
 * jsp meme pas frr c bon
 * 
 * 
*/
void	send_char(char *message)
{
	int	i;
	int	tosend;

	i = 0;
	while (message[i++])
	{
		tosend = dec_to_bin(message[i]);
	}
}

int	send_sig_to_pid(int pid, int signum)
{
	if (kill(pid, signum) == -1)
		return (-1);
	return (0);
}

int	main(int ac, char **av)
{
	int	test;
	int	signum;
	int	targetpid;

	if (ac != 3)
		return (0);
	printf("coucou je client\n");
	printf("test fonction eight_bits_value : %s\n", eight_bits_value());
	signum = SIGUSR1;
	targetpid = atoi(av[1]);
	test = dec_to_bin(av[2][0]);
	printf("parametre 2 : %s\n", av[2]);
	printf("test en binaire : %d\n", test);
	if (send_sig_to_pid(targetpid, signum) == 0)
		printf("Signal envoyé au PID %d avec succès.\n", targetpid);
	return (0);
}
