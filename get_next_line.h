/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldenis <ldenis@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 09:56:36 by ldenis            #+#    #+#             */
/*   Updated: 2020/12/10 11:35:35 by ldenis           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

char	*ft_strfjoin(char *s1, char *s2, int is_free);
int		get_next_line(int fd, char **line);
char	*ft_strdup(const char *s1);
int		ft_strichr(const char *s, int c);
char	*ft_subfstr(char const *s, unsigned int start, size_t len, int is_free);
size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strtrim(char const *s1, char const *set);

#endif
