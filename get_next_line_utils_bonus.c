/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldenis <ldenis@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 17:20:13 by ldenis            #+#    #+#             */
/*   Updated: 2020/12/07 16:38:31 by ldenis           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strfjoin(char *s1, char *s2, int is_free)
{
	size_t		len;
	char		*str;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = (char *)ft_calloc(sizeof(char), len + 1)))
		return (NULL);
	ft_memcpy((void *)str, (const void *)s1, ft_strlen(s1));
	ft_strlcat((char *)str, (char *)s2, len + 2);
	if (is_free == 1)
		free(s1);
	else if (is_free == 2)
		free(s2);
	else if (is_free != 0)
	{
		free(s1);
		free(s2);
	}
	return (str);
}

int		ft_strichr(const char *s, int c)
{
	char	*temp_s;
	int		i;

	i = 0;
	temp_s = (char *)s;
	if (!c)
		return (ft_strlen(s));
	while ((size_t)i < ft_strlen(s))
	{
		if (temp_s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_subfstr(char const *s, unsigned int start, size_t len, int is_free)
{
	char	*dst;
	size_t	i;
	int		size;

	i = 0;
	if (start >= ft_strlen(s))
	{
		if (is_free == 1)
			free((void *)s);
		return (ft_calloc(1, 1));
	}
	size = (ft_strlen(s) > len) ? len : (ft_strlen(s) - start);
	if (!(dst = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (i < len && s[start])
	{
		dst[i] = s[start];
		i++;
		start++;
	}
	dst[i] = '\0';
	if (is_free == 1)
		free((void *)s);
	return (dst);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t		n;
	size_t		dest_size;
	size_t		i;

	dest_size = 0;
	n = size;
	while (dest[dest_size] && n--)
		dest_size++;
	n = dest_size;
	if (n == size)
		return (dest_size + ft_strlen(src));
	i = -1;
	while (src[++i] && n < size - 1)
		dest[n++] = src[i];
	dest[n] = 0;
	return (dest_size + ft_strlen(src));
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*temp;
	size_t			i;

	i = 0;
	temp = (unsigned char *)b;
	while (i < len)
		temp[i++] = c;
	return (b);
}
