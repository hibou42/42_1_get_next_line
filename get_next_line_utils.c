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

void	*ft_memmove(void *dst, const void *src, size_t size)
{
	size_t			i;

	i = 0;
	if (dst == src || size == 0)
		return (dst);
	if (dst > src)
	{
		while (size > 0)
		{
			((unsigned char *)dst)[size - 1] = ((unsigned char *)src)[size - 1];
			size--;
		}	
	}
	else
	{
		while (i < size)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dst);
}

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
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
