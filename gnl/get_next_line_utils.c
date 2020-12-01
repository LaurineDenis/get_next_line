/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldenis <ldenis@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 09:56:34 by ldenis            #+#    #+#             */
/*   Updated: 2020/12/01 15:42:47 by ldenis           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strjoin(char *s1, char *s2)
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
	return (str);
}

char	*ft_strdup(const char *s1)
{
	size_t		i;
	size_t		j;
	char		*str;

	i = ft_strlen(s1);
	j = 0;
	if (!(str = (char*)malloc(sizeof(char) * i + 1)))
		return (0);
	while (j < i)
	{
		str[j] = s1[j];
		j++;
	}
	str[j] = '\0';
	if (str == NULL)
		return (0);
	return (str);
}

size_t		ft_strchr(const char *s, int c)
{
	char	*temp_s;
	size_t	i;

	i = 0;
	temp_s = (char *)s;
	if (!c)
		return (ft_strlen(s));
	while (i < ft_strlen(s))
	{
		if (temp_s[i] == c)
			return (i);
		i++;
	}
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;
	int		size;

	i = 0;
	if (start >= ft_strlen(s))
		return (ft_calloc(1, 1));
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
	return (dst);
}

size_t		ft_strlen(const char *s)
{
	size_t		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strnlen(const char *s, size_t n)
{
	size_t i;

	i = 0;
	while (s[i] && n--)
		i++;
	return (i);
}

size_t			ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t		n;
	size_t		dest_size;
	size_t		i;

	n = ft_strnlen(dest, size);
	dest_size = n;
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

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;

	if (!(ret = malloc(size * count)))
		return (0);
	ft_memset(ret, 0, size * count);
	return (ret);
}
