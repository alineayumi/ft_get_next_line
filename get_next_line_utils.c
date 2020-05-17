/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 14:00:41 by afukuhar          #+#    #+#             */
/*   Updated: 2020/04/28 16:58:59 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	get_line_size(char *line)
{
	size_t size;

	size = 0;
	while(*line != '\n')
	{
		size++;
		line++;
	}
	return (size);
}
