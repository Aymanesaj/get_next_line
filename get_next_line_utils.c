/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:43:55 by asajed            #+#    #+#             */
/*   Updated: 2024/11/15 23:54:09 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*dst;

	dst = (unsigned char *)b;
	while (len--)
	{
		*dst = (unsigned char) c;
		dst++;
	}
	return (b);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*s;
	
	if (count == 0 || size == 0)
		return (NULL);
	if (count > SIZE_MAX / size)
		return (NULL);
	s = malloc(count * size);
	if (!s)
		return (NULL);
	ft_memset (s, 0, count * size);
	return (s);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*to_dst;
	const unsigned char	*to_src;

	to_dst = (unsigned char *)dst;
	to_src = (const unsigned char *)src;
	if (to_dst == to_src || !n)
		return (dst);
	i = 0;
	if (to_dst == to_src || !n)
		return (dst);
	while (i < n)
	{
		to_dst[i] = to_src[i];
		i++;
	}
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*v;
	size_t	s_len;
	size_t	i;

	if (!s)
		return (NULL);
	s_len = 0;
	i = 0;
	while (s[s_len])
		s_len++;
	if (start >= s_len)
		return (ft_calloc(1, 1));
	if (len > s_len - start)
		len = s_len - start;
	v = (char *)ft_calloc(len + 1, 1);
	if (!v)
		return (NULL);
	while (i < len && s[start])
	{
		v[i] = s[start];
		i++;
		start++;
	}
	v[i] = '\0';
	return (v);
}
