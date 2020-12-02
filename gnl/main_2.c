/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldenis <ldenis@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:15:27 by ldenis            #+#    #+#             */
/*   Updated: 2020/12/02 16:41:41 by ldenis           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stdlib.h"
#include "unistd.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include "get_next_line.h"

int			ft_main(int ac, char **av)
{
	int		fd;
    int     ret;
	char	*line;
    int     count = 0;

	line = NULL;
	(void)ac;
	fd = open(av[1], O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0 && count != 60)
	{
		dprintf(1, "%d |%s|\n", ret, line);
        free(line);
        count++;
	}
	dprintf(1, "%d |%s|\n", ret, line);
	free(line);
    dprintf(1, "LIGNE LUE(S) : %d\n", count);
	close(fd);
}

int	main(int ac, char **av)
{
	ft_main(ac, av);
	// while (1)
	// 	;
	return (0);
}
