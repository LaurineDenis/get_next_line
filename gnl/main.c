/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldenis <ldenis@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 11:21:08 by ldenis            #+#    #+#             */
/*   Updated: 2020/12/01 12:20:49 by ldenis           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int ac, char **av)
{
   char	*line;
   int		fd;
   int		value;
   int		i;
   i = 1;
   // if (ac == 1)
   // {
   //    value = 1;
   //    while (value == 1)
   //    printf("+%d+\n", get_next_line(0, &line));
   //    return (0);
   // }
   // while (i < ac)
   // {
      value = 1;
      fd = open(av[i], O_RDONLY);
      while (value == 1)
      {
         value = get_next_line(fd, &line);
         printf("line = %s\n", line);
         printf("value = %d\n", value);
         if (value == 0)
            {
               break;
               free(line);
               close(fd);
            }
         else
            value = 2;
         free(line);
      }
   // i++;
   printf("---------------------------\n");
   // }
   return (0);
}
