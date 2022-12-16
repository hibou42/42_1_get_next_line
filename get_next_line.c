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

void	finalcut(char *res, char *statik, int pos, int len)
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
	tmp = ft_calloc(len, sizeof(char));
	while(statik[i + 1 + i2])
	{
		tmp[i2] = statik[i + 1 + i2];
		i2++;
	}
	free(statik);
	statik = malloc((i + i2 + 1) * sizeof(char));
	statik = tmp;
	free(tmp);
}

int	readmore(char *statik, int fd, int len)
{
	char	*tmp;
	char	*buffer;
	int		i;
	int		check;

	tmp = ft_calloc(len, sizeof(char));
	i = 0;
	while (!statik && statik[i])
	{
		tmp[i] = statik[i];
		i++;
	}
	tmp[i] = '\0';
	free(statik);
    statik = NULL;
    buffer = NULL;
	check = read(fd, buffer, BUFFER_SIZE);
	statik = ft_strjoin(tmp, buffer);
	free(tmp);
	return (check);
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
	int			pos;
	int			check;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!statik)
        statik = ft_calloc(1, sizeof(char));
    while (1)
	{
		pos = checkline(statik);
		if (pos == -1)
		{
			check = readmore(statik, fd, ft_strlen(statik));
			if (check == 0)
            {
				free(statik);
                return (NULL);
            }
		}
		else
		{
			res = ft_calloc(pos, sizeof(char));
			finalcut(res, statik, pos - 1, ft_strlen(statik) + 1);
			return (res);
		}
	}
}