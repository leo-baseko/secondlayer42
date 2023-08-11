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

static void	ft_signal_handler(int sig)
{
	static int	i;
	static char	c;

	if (sig == SIGUSR1)
		c |= 1 << i;
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	write(1, "PID : ", 6);
	while (1)
	{
		signal(SIGUSR1, ft_signal_handler);
		signal(SIGUSR2, ft_signal_handler);
		pause();
	}
	return (0);
}
