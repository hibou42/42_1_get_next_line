/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:44:36 by aschaefe          #+#    #+#             */
/*   Updated: 2022/11/22 13:59:21 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_buffer(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*get_next_line(int fd)
{
	static char	*statik;
	char		buffer[BUFFER_SIZE + 1];
	char		*res;

	res = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (statik)
	{
		res = ft_memmove(res, statik, ft_strlen(statik));
		ft_bzero(statik, ft_strlen(statik));
	}
	while (1)
	{
		read(fd, buffer, BUFFER_SIZE);
		if (check_buffer(buffer) >= 0)
		{
			res = ft_strjoin(res, buffer);
			break ;
		}
		res = ft_strjoin(res, buffer);
	}
	return (res);
}
