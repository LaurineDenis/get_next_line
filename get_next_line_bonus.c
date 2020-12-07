/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldenis <ldenis@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 09:56:34 by ldenis            #+#    #+#             */
/*   Updated: 2020/12/07 16:59:07 by ldenis           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*tmp_dest;
	unsigned char	*tmp_src;
	size_t			i;

	tmp_dest = (unsigned char *)dest;
	tmp_src = (unsigned char *)src;
	i = -1;
	if (dest == 0 && src == 0)
		return (0);
	while (++i < n)
		tmp_dest[i] = tmp_src[i];
	return (dest);
}

void		*ft_calloc(size_t count, size_t size)
{
	void	*ret;

	if (!(ret = malloc(size * count)))
		return (0);
	ft_memset(ret, 0, size * count);
	return (ret);
}

size_t		ft_strlen(const char *s)
{
	size_t		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int			fill_line(char **stock, char **line, int end)
{
	int		value;

	value = ft_strichr(*stock, '\n');
	if (value == -1)
	{
		value = ft_strichr(*stock, '\0');
		if (!(*line = ft_subfstr(*stock, 0, value, 0)))
			return (-1);
		if (stock)
			free(*stock);
		*stock = ft_calloc(1, 1);
		return (0);
	}
	if (end == 0)
		return (0);
	else
	{
		if (!(*line = ft_subfstr(*stock, 0, value, 0)))
			return (-1);
		if (!(*stock = ft_subfstr(*stock, value + 1, ft_strlen(*stock), 1)))
			return (-1);
		return (1);
	}
}

int			get_next_line(int fd, char **line)
{
	static char	*stock[4098] = {0};
	char		buffer[BUFFER_SIZE + 1];
	int			end;

	end = 1;
	if (BUFFER_SIZE == 0 || !line || fd < 0)
	{
		line = NULL;
		return (-1);
	}
	if (stock[fd] == NULL && !(stock[fd] = ft_calloc(1, 1)))
		return (-1);
	if (stock[fd] == '\0' || ft_strichr(stock[fd], '\n') == -1)
	{
		while ((end = read(fd, buffer, BUFFER_SIZE)) > 0)
		{
			buffer[end] = '\0';
			stock[fd] = ft_strfjoin(stock[fd], buffer, 1);
			if (ft_strichr(buffer, '\n') != -1)
				break ;
		}
	}
	if (end == -1)
		return (-1);
	return (fill_line(&stock[fd], line, end));
}
