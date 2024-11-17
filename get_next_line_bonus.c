/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:57:05 by asajed            #+#    #+#             */
/*   Updated: 2024/11/17 22:17:16 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	buff_size(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\n' && s[i])
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char *update(char **buffer, char *gline, int len)
{
    char *temp;

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

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*gline;
	int			bytes;
	int			len;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer[fd])
	{
		buffer[fd] = ft_calloc((BUFFER_SIZE + 1), 1);
		if (!buffer[fd])
			return (NULL);
	}
	bytes = 1;
	gline = NULL;
	len = 0;
	while (bytes > 0)
	{
		if (buffer[fd][0] == '\0')
		{
			bytes = read(fd, buffer[fd], BUFFER_SIZE);
			if (bytes <= 0)
				break ;
			buffer[fd][bytes] = '\0';
		}
		len = buff_size(buffer[fd]);
		gline = update(&buffer[fd], gline, len);
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
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
	}
	return (NULL);
}
