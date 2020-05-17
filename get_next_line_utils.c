/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 14:00:41 by afukuhar          #+#    #+#             */
/*   Updated: 2020/05/16 22:56:25 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_strnew(size_t size)
{
	char *new_str;

	if (!(new_str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_bzero(new_str, size + 1);
	return (new_str);
}

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t src_len;
	size_t dst_len;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (dstsize < dst_len)
		return (src_len + dstsize);
	dst += dst_len;
	ft_strlcpy(dst, src, dstsize - dst_len);
	return (src_len + dst_len);
}

size_t	ft_strlcpy(char *restrict dst, const char *restrict src,
	size_t dstsize)
{
	size_t src_len;

	if (!dst || !src)
		return (0);
	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	while (*src && dstsize-- > 1)
		*dst++ = *src++;
	*dst = '\0';
	return (src_len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *str;

	if (!(str = ft_strnew(len)) || !s)
		return (NULL);
	if (start >= ft_strlen(s))
		ft_bzero(str, len + 1);
	else
	{
		s += start;
		ft_strlcpy(str, s, len + 1);
	}
	return (str);
}
