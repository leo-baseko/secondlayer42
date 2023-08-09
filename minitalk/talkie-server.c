/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   talkie-server.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:45:01 by ldrieske          #+#    #+#             */
/*   Updated: 2023/08/09 15:10:43 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_receivedsignal = 0;

void	sig_handler(int signum)
{
	(void) signum;
	g_receivedsignal = 1;
}

int	main(void)
{
	int				handled_sig[] = {SIGINT, SIGTERM, SIGUSR1, SIGUSR2};
	unsigned long	i;

	i = 0;
	while (i < sizeof(handled_sig) / sizeof(handled_sig[0]))
		signal(handled_sig[i++], sig_handler);
	printf("Le programme s'exécute. Attente d'n signal...\n");
	printf("Le PID du processus en cours est : %d\n", getpid());
	while (!g_receivedsignal)
	{
	}
	printf("Signal recu. Le programme se termine. Terminé bonsoir.\n");
	return (0);
}
