/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldenis <ldenis@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 17:20:13 by ldenis            #+#    #+#             */
/*   Updated: 2020/12/02 17:28:24 by ldenis           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	ft_strdel(char **s)
{
	if (*s)
	{
		free(s);
		*s = NULL;
	}
}

int		get_next_line(int fd, char **line)
{
	static char	*stock;
	char		buffer[BUFFER_SIZE + 1];
	int			value;

	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		buffer[BUFFER_SIZE] = '\0';
		value = ft_strchr(buffer, '\n');
	}
}
