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

void	*finalcut(char *res, char *statik, int pos)
{
	char	*tmp;
	int		i;
	int		i2;

	i = 0;
	while(i <= pos)
	{
		res[i] = statik[i];
		i++;
	}
	i2 = 0;
	while(statik[i])
	{
		tmp[i2] = statik[i + i2];
		i2++;
	}
	free(statik);
	tmp = malloc((i + i2 + 1) * sizeof(char));
	statik = tmp;
}

void	readmore(char *statik, int fd)
{
	char	*tmp;
	char	*buffer;
// il faut malloc le buffer et le free
	tmp = statik;
	free(statik);
	read(fd, buffer, BUFFER_SIZE);
	statik = ft_strjoin(tmp, buffer);
}

int	checkline(char *str)
{
	int	i;

	i = 0;
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
	char		*tmp;
	int			pos;

    if (fd < 0 || BUFFER_SIZE < 1)
        return (NULL);
	if (!statik)
		statik = malloc(1 * sizeof(char));
	while (1)
	{
		pos = checkline(statik);
		if (pos == -1)
			readmore(statik, fd);
		else
		{
			finalcut(res, statik, pos);
			return (res);
		}
	}
}