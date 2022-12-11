/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:50:32 by aschaefe          #+#    #+#             */
/*   Updated: 2022/11/22 12:21:54 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int	main(int ac, char **av)
{
	int	fd;
	(void) ac;
	(void) av;

	fd = open("text.txt", O_RDONLY);
	int	i = 0;
	while(i < 3)
	{
	//	get_next_line(fd);
		i++;
	}
	close(fd);
	return (0);
}
