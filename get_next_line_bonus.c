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

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	int		len;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s2)
		return (s1);
	if (!s1)
		return (s2);
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	len = i + j;
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, i);
	ft_memcpy(str + i, s2, j);
	str[len] = '\0';
	free(s1);
	free(s2);
	return (str);
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

char *get_next_line(int fd)
{
    static char *buffer[OPEN_MAX]; 
    char 		*gline;
    int 		bytes;
    int 		len;

    if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
        return (NULL);
	if (!buffer[fd])
        buffer[fd] = calloc(BUFFER_SIZE + 1, sizeof(char));
	bytes = 1;
	gline = NULL;
	len = 0;
    while (bytes > 0)
    {
        if (buffer[fd][0] == '\0')
        {
            bytes = read(fd, buffer[fd], BUFFER_SIZE);
            if (bytes <= 0)
                break;
            buffer[fd][bytes] = '\0';
        }
        len = buff_size(buffer[fd]);
        gline = ft_strjoin(gline, ft_substr(buffer[fd], 0, len));
		if (!gline)
            return (NULL);
        if (checkline(gline, bytes) == 1)
		{
			ft_memcpy(buffer[fd], buffer[fd] + len, BUFFER_SIZE - len + 1);
			return (gline);
		}
        ft_memset(buffer[fd], 0, BUFFER_SIZE + 1);
    }
    if (bytes == 0 && gline && gline[0] != '\0')
        return (gline);
    free(gline);
    return (NULL);
}
