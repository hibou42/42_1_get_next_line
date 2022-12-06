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

void	*ft_calloc(size_t nb, size_t size)
{
	void	*ptr;
	char    *str;
	size_t  i;

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
