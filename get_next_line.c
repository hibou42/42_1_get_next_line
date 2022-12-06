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

char	*get_next_line(int fd)
{
	static char	*statik;
	char		buffer[BUFFER_SIZE + 1];
	int			index
	int			retour;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	while (1)
	{
		//read les char et add dans le buffer
		//check if \n
		//	yes : write in statik and return
		//	no : continue
		break;
	}
	if (!statik)
		return (NULL);
	return (statik);
}
