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

char	*statikcut(char *statik, int pos)
{
	char	*res;
	int 	len;
	int 	i;

	len = ft_strlen(statik) - pos;
	res = ft_calloc(len + 1, sizeof(char));
	i = 0;
	while (statik[i + pos])
	{
		res[i] = statik[i + pos];
		i++;
	}
	free(statik);
	res[i] = '\0';
	return (res);
}

char	*rescut(char *statik, int pos)
{
	char	*res;
	int 	i;

	res = ft_calloc(pos + 1, sizeof(char));
	i = 0;
	while (i <= pos)
	{
		res[i] = statik[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*readmore(char *statik, int fd, int *readret)
{
	char	buffer[BUFFER_SIZE + 1];
	int 	tmp;

	tmp = read(fd, buffer, BUFFER_SIZE);
	*readret = tmp;
	if (tmp == -1)
	{
		return (statik);
	}
	buffer[tmp] = '\0';
	statik = ft_strjoin(statik, buffer);
	return (statik);
}

int	checkline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while(str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*get_next_line(int fd)
{
	static char	*statik;
	char		*res;
	int 		readret;
	int		pos;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!statik)
        statik = ft_calloc(1, 1);
	while (1)
	{
		pos = checkline(statik);
		if (pos == -1)
			{
			statik = readmore(statik, fd, &readret);
			if ((readret == -1 || readret == 0) && statik)
				return (statik);
		}
		else
		{
			res = rescut(statik, pos);
			statik = statikcut(statik, pos + 1);
			return (res);
		}
	}
}
