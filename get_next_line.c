/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:43:30 by asajed            #+#    #+#             */
/*   Updated: 2024/11/15 23:51:46 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	char	*str;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s2)
		return (s1);
	if (!s1)
		return (s2);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	str = (char *)malloc(i + j + 1);
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, i);
	ft_memcpy(str + i, s2, j);
	str[i + j] = '\0';
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

char	*get_next_line(int fd)
{
	static int	i;
	static char	buffer[BUFFER_SIZE + 1];
	static int	bytes;
	char		*gline;
	int			k;

	if (i >= bytes)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		i = 0;
		if (bytes <= 0)
		{
			ft_memset(buffer, 0, BUFFER_SIZE + 1);
			return (NULL);
		}
		buffer[bytes] = '\0';
	}
	k = i;
	i += buff_size(buffer + i);
	gline = ft_substr(buffer, k, i - k);
	if (checkline(gline, bytes) == 0)
		gline = ft_strjoin(gline, get_next_line(fd));
	if (!gline)
		return (NULL);
	return (gline);
}
