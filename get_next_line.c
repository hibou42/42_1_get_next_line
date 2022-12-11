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

//	printf("ft final cut begin // statik = %s /\n", statik);
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
//	printf("ft final cut end // statik = %s /\n", statik);
//	printf("ft final cut end // tmp = %s /\n", tmp);
	free(tmp);
}

int	readmore(char *statik, int fd, int len)
{
	char	*tmp;
	char	*buffer;
	int		i;
	int		check;

//	printf("ft readmore begin // statik = %s /\n", statik);
	buffer = ft_calloc(BUFFER_SIZE, sizeof(char));
//	printf("ft readmore begin // buffer = %s /\n", buffer);
	tmp = ft_calloc(len, sizeof(char));
	i = 0;
	while (statik[i])
	{	
		tmp[i] = statik[i];
		i++;
	}
	tmp[i] = '\0';
	free(statik);
	check = read(fd, buffer, BUFFER_SIZE);
	statik = ft_strjoin(tmp, buffer);
	free(tmp);
//	printf("ft readmore end // statik = %s /\n", statik);
//	printf("ft readmore end // buffer = %s /\n", buffer);
	return (check);
}

int	checkline(char *str)
{
	int	i;
	
//	printf("ft checkline // str = %s /\n", str);
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
	int			pos;
	int			check;

	
//	printf("First in gnl\n");
	if (fd < 0 || BUFFER_SIZE < 1)
        	return (NULL);
	if (!statik)
		statik = ft_calloc(1, sizeof(char));
	while (1)
	{
		printf("boucle(1) // statik = %s /\n", statik);
		pos = checkline(statik);
		printf("boucle(1) // pos = %d /\n", pos);
			if (pos == -1)
		{
			check = readmore(statik, fd, ft_strlen(statik) + 1);
//			printf("check = %d /\n statik after readmore %s\n", check, statik);
			if (check == 0)
				return (NULL);
		}
		else
		{
			res = ft_calloc(pos, sizeof(char));
			finalcut(res, statik, pos - 1, ft_strlen(statik) + 1);
			return (res);
		}
	}
}
