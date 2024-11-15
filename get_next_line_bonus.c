/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:57:05 by asajed            #+#    #+#             */
/*   Updated: 2024/11/15 15:57:07 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_checkline(char *buffer,int fd)
{
	int		i;
	char	*line;
	char	*tmp;

	i = 0;
	while (buffer[i])
	{
		while (buffer[i] != '\n' && buffer[i])
			i++;
		if (buffer[i] == '\n')
			i++;
		else if (buffer[i] != '\n')
		{
			
			ft_read(buffer ,fd);
		}
	}
	line = (char *)malloc(i + 1);
	if (!line)
		return (NULL);
	line[i] = '\0';
	while (i >= 0)
	{
		line[i] = buffer[i];
		i--;
	}
	return (line);
}

char *ft_read(char *buffer, int fd)
{
	int bytes;

	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes <= 0)
		return (NULL);
	return(buffer);
}

char *get_next_line(int fd)
{
	static char *buffer[OPEN_MAX];
	char		*line;

	buffer[fd] = ft_read(buffer[fd], fd);
	line = ft_checkline(buffer[fd], fd);
	if (!line)
		return (NULL);
	return (line);
}