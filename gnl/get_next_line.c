/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldenis <ldenis@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 09:56:31 by ldenis            #+#    #+#             */
/*   Updated: 2020/12/02 17:35:59 by ldenis           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_strdel(char **s)
{
	if (*s)
	{
		free(*s);
		*s = NULL;
	}
}

int		fill_line(char **stock, char **line, int value)
{
	value = ft_strchr((*stock), '\n');
	//dprintf(1, "value = %d\n", value);
	if (!(*line = ft_substr((*stock), 0, value)))
		return (-1);
	// printf("line = %s\n", line);
	printf("len stock = %zu\n", ft_strlen(*stock));
	// if (*stock != '\0')
	if (ft_strlen(*stock) != 0)
	{
		// printf("stock avant = %s\n", (*stock));
		if (!((*stock) = ft_substr((*stock), value + 1, ft_strlen((*stock)))))
			return (-1);
		// printf("stock apres = %s\n", (*stock));
		return (1);
	}
	ft_strdel(stock);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*stock;
	char		*rest;
	int			value;

	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		buffer[BUFFER_SIZE] = '\0';
		value = ft_strchr(buffer, '\n');
		if (value > 0)
		{
			//dprintf(1, "sortie 1\n");
			if ((stock) != 0)
			{
				//printf("sortie 1\n");
				// printf("stock = %s\n", (*stock));
				if (fill_line(&stock, line, value) == -2)
					return (-1);
				else if (fill_line(&stock, line, value) != 0)
				{
					//dprintf(1, "sortie 1,2\n");
					if (!((stock) = ft_strfjoin(stock, buffer, 1)))
						return (-1);
					return (1);
				}
				else
				{
					//dprintf(1, "sortie 1,5\n");
					if (!(rest = ft_substr(buffer, 0, value)))
						return (-1);
					// printf("rest = %s\n", (*rest));
					if (!((*line) = ft_strfjoin(stock, rest, 2)))
						return (-1);
					if (!((stock) = ft_substr(buffer, value + 1, BUFFER_SIZE)))
						return (-1);
					return (1);
				}
			}
			else if (value <= BUFFER_SIZE)
			{
				//dprintf(1, "sortie 2\n");
				if (!((*line) = ft_substr(buffer, 0, value)))
					return (-1);
				if (!((stock) = ft_substr(buffer, value + 1, BUFFER_SIZE)))
					return (-1);
				// printf("stock = %s\n", (*stock));
				return (1);
			}
		}
		else
		{
			if (stock != 0)
			{
				// dprintf(1, "sortie 3\n");
				// dprintf(1, "stock = %s\n", stock);
				// dprintf(1, "buffer = %s\n", buffer);
				if (!(stock = ft_strfjoin(stock, buffer, 1)))
					return (-1);
				// dprintf(1, "buffer = %s\n", buffer);
			}
			else
			{
				// dprintf(1, "sortie 4\n");
				if (!((stock) = ft_substr(buffer, 0, BUFFER_SIZE)))
					return (-1);
			}
		}
	}
	if (stock != 0)
		return (fill_line(&stock, line, value));
	return (0);
}

