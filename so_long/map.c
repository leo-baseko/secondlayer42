/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:59:41 by ldrieske          #+#    #+#             */
/*   Updated: 2023/08/23 14:38:25 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	does_map_exists(int fd)
{
	if (!fd)
		return (1);
	return (0);
}

int	is_map_rect(int fd)
{
	int	i;
	int	j;

	if (does_map_exists(fd) == 1)
		return (1);
	i = 0;
	//do a loop to see if all ligns are the same length as the first one
	//if not, return 1
}

int	main()
{
	int	fd;

	fd = open("map_test.ber", O_RDONLY);
	printf("est-ce que la map est rectangle ? : %d\n", is_map_rect(fd));
	close(fd);
	return (0);
