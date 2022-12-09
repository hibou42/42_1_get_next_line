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

	tmp = ft_calloc(len, sizeof(char));
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
	statik = ft_calloc((i + i2 + 1), sizeof(char));
	statik = tmp;
	free(tmp);
}

int	readmore(char *statik, int fd, int len)
{
	char	*tmp;
	char	buffer[BUFFER_SIZE];
	int		i;
	int		check;

	printf("ft readmore begin // statik = %s /\n", statik);
	tmp = ft_calloc(len, sizeof(char));
	i = 0;
	while (statik[i])
	{	
		tmp[i] = statik[i];
		i++;
	}
	free(statik);
	check = read(fd, buffer, BUFFER_SIZE);
	statik = ft_strjoin(tmp, buffer);
	free(tmp);
	printf("ft readmore end // statik = %s /\n", statik);
	return (check);
}

int	checkline(char *str)
{
	int	i;
	
	printf("ft checkline begin // str = %s /\n", str);
	i = 0;
	while(str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	str[i] = '\0';
	printf("ft checkline end // str = %s /\n", str);
	return (-1);
}

char	*get_next_line(int fd)
{
	static char	*statik;
	char		*res;
	int			pos;
	int			check;

	
	printf("First in gnl\n");
	if (fd < 0 || BUFFER_SIZE < 1)
        	return (NULL);
	if (!statik)
		statik = ft_calloc(1, sizeof(char));
	printf("After check in gnl\n");
	while (1)
	{
		printf("boucle(1) // statik = %s /\n", statik);
		pos = checkline(statik);
		if (pos == -1)
		{
			check = readmore(statik, fd, ft_strlen(statik) + 1);
			if (check == 0)
				return (NULL);
		}
		else
		{
			res = ft_calloc(pos + 1, sizeof(char));
			finalcut(res, statik, pos, ft_strlen(statik) + 1);
			return (res);
		}
	}
}
