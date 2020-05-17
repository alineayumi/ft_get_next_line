/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 13:40:08 by afukuhar          #+#    #+#             */
/*   Updated: 2020/05/16 22:44:33 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	ssize_t		r;
	char		buf[BUFFER_SIZE + (r = 1)];
	char		*tmp;
	static char	*cl[FD_SIZE];
	char		*end;

	if ((!cl[fd] && !(cl[fd] = ft_strnew(0))) || fd < 0 || !line)
		return (-1 * ft_delete(cl[fd]));
	while (!ft_strchr(cl[fd], '\n') && (r = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[r] = '\0';
		tmp = cl[fd];
		cl[fd] = ft_strjoin(cl[fd], buf);
		ft_delete(tmp);
	}
	if (r == -1 || BUFFER_SIZE < 1)
		return (-1 * ft_delete(cl[fd]));
	end = (ft_strchr(cl[fd], ft_strchr(cl[fd], '\n') ? '\n' : '\0'));
	*line = (!*cl[fd] ? ft_strnew(0) : ft_substr(cl[fd], 0, end - cl[fd]));
	tmp = cl[fd];
	cl[fd] = (*end == '\0' ? 0 : ft_substr(tmp, (end - tmp) + 1,
		ft_strlen(end + 1)));
	ft_delete(tmp);
	end = NULL;
	return (r == 0 ? 0 * ft_delete(cl[fd]) : 1);
}

size_t	ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (*s++ != '\0')
		len++;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = ft_strnew(len)))
		return (NULL);
	ft_strlcpy(str, s1, len + 1);
	ft_strlcat(str, s2, len + 1);
	return (str);
}

int		ft_delete(char *str)
{
	if (str)
	{
		ft_bzero(str, ft_strlen(str));
		free(str);
		str = NULL;
		return (1);
	}
	return (0);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char *ptr_to_b;

	ptr_to_b = (unsigned char *)s;
	while (n > 0)
	{
		*ptr_to_b = 0;
		n--;
		ptr_to_b++;
	}
}
