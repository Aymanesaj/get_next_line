/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:57:05 by asajed            #+#    #+#             */
/*   Updated: 2024/11/18 18:14:16 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	lenght(char *s, char *till_newline)
{
	size_t	i;

	i = 0;
	if (!s && !till_newline)
		return (-1);
	if (till_newline && !s)
	{
		while (till_newline[i] != '\n' && till_newline[i])
			i++;
		if (till_newline[i] == '\n')
			i++;
	}
	if (s && !till_newline)
	{
		while (s[i])
			i++;
	}
	return (i);
}

char	*update(char **buffer, char *gline, int len)
{
	char	*temp;

	temp = ft_strjoin(gline, ft_substr(*buffer, 0, len));
	if (!temp)
		return (NULL);
	ft_memcpy(*buffer, *buffer + len, BUFFER_SIZE - len + 1);
	return (temp);
}

int	checkline(char *gline, int bytes)
{
	int	i;

	i = 0;
	while (gline[i] != '\n' && gline[i])
		i++;
	if (gline[i] != '\n' && bytes == 0 && gline[0] != '\0')
		return (1);
	return (gline[i] == '\n');
}

int	read_and_allocate(int fd, char **buffer)
{
	if (!*buffer)
	{
		*buffer = ft_calloc((BUFFER_SIZE + 1), 1);
		if (!*buffer)
			return (-1);
	}
	if ((*buffer)[0] == '\0')
		return (read(fd, *buffer, BUFFER_SIZE));
	return (BUFFER_SIZE);
}

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*gline;
	int			bytes;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	bytes = 1;
	gline = NULL;
	while (bytes > 0)
	{
		bytes = read_and_allocate(fd, &buffer[fd]);
		if (bytes <= 0)
			break ;
		buffer[fd][bytes] = '\0';
		gline = update(&buffer[fd], gline, lenght(NULL, buffer[fd]));
		if (!gline)
			return (NULL);
		if (checkline(gline, bytes))
			return (gline);
		ft_memset(buffer[fd], 0, BUFFER_SIZE + 1);
	}
	if (bytes == 0 && gline && gline[0] != '\0')
		return (gline);
	if (gline)
		free(gline);
	if (buffer[fd])
		free(buffer[fd]);
	return (NULL);
}
