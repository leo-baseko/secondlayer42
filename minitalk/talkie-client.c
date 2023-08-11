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

static void	ft_send(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & 1 << i)
		{
			if (pid != -1)
				kill(pid, SIGUSR1);
		}
		else
		{
			if (pid != -1)
				kill(pid, SIGUSR2);
		}
		i++;
		usleep(100);
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	pid;

	i = 0;
	if (ac == 3)
	{
		pid = atoi(av[1]);
		if (pid <= 0)
			return (1);
		while (av[2][i])
			ft_send(pid, av[2][i++]);
		ft_send(pid, '\n');
	}
	return (0);
}
