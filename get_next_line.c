/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 13:40:08 by afukuhar          #+#    #+#             */
/*   Updated: 2020/04/29 16:16:10 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	char		*tmp;
	static char	buf[BUFFER_SIZE];
	static int	i;

	i = 0;
	read(fd, buf, BUFFER_SIZE);
	tmp = malloc(sizeof(char) * size);
	read();
}
