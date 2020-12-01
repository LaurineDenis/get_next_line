/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldenis <ldenis@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 09:56:31 by ldenis            #+#    #+#             */
/*   Updated: 2020/12/01 15:44:31 by ldenis           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	char		buffer[BUFFER_SIZE + 1];
	char		*stock[256];
	int			i;
	static char *rest;
	int			value;

	i = 0;
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		buffer[BUFFER_SIZE] = '\0';
		value = ft_strchr(buffer, '\n');
		if (value > 0)
		{
			if (i != 0)
				ft_strjoin((char *)stock, (buffer + value));
			(*line) = ft_substr(buffer, 0, (value - ft_strlen(buffer)));
			rest = ft_substr(buffer, value, ft_strlen(buffer));
			i = 0;
			return (1);
		}
		else
		{
			stock[i] = ft_strdup(buffer + i);
			i++;
		}
	}
	return (0);
}

