/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:52:25 by aschaefe          #+#    #+#             */
/*   Updated: 2022/11/22 13:58:29 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		len;

	if (! s1 || ! s2)
		return (NULL);
	res = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (! res)
		return (NULL);
	len = 0;
	i = 0;
	while (s1[i] != '\0')
		res[len++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		res[len++] = s2[i++];
	res[len] = '\0';
	return (res);
}

void	*ft_calloc(size_t nb, size_t size)
{
	void	*ptr;
	char	*str;
	size_t	i;

	ptr = malloc(nb * size);
	if (ptr)
	{
		str = (char *)ptr;
		i = 0;
		while (i < nb * size)
		{
			str[i] = 0;
			i++;
		}
		return (ptr);
	}
	return (NULL);
}
