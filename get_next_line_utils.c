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
	size_t			i;
	unsigned char	*dst;

	dst = b;
	i = 0;
	while (i < len)
	{
		dst[i] = (unsigned char) c;
		i++;
	}
	return (b);
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

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	p;

	p = 0;
	while (src[p])
		p++;
	i = 0;
	if (dstsize > 0)
	{
		while (i < dstsize - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (p);
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

	if (!s)
		return (NULL);
	s_len = 0;
	while (s[s_len])
		s_len++;
	if (start >= s_len)
		return (malloc(1));
	if (len > s_len - start)
		len = s_len - start;
	v = (char *)malloc(len + 1);
	if (v == NULL)
		return (NULL);
	ft_strlcpy(v, s + start, (len + 1));
	return (v);
}
