/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:35:31 by aschaefe          #+#    #+#             */
/*   Updated: 2022/11/22 13:58:27 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

char	*get_next_line(int fd);
int		checkline(char *str);
int		ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_calloc(size_t nb, size_t size);

#endif
