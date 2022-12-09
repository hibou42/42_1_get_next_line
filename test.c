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
int	main(void)
{
	int	fd;

	fd = open("text", O_RDONLY);
	get_next_line(fd);
	close(fd);
	return (0);
}
