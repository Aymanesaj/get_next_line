/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 19:47:38 by asajed            #+#    #+#             */
/*   Updated: 2024/11/17 21:29:08 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
		return (malloc(1));
	if (len > s_len - start)
		len = s_len - start;
	v = (char *)malloc(len + 1);
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
