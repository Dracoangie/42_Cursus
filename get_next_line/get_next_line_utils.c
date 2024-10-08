/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:16:56 by angnavar          #+#    #+#             */
/*   Updated: 2024/10/08 18:28:58 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *src)
{
	int		i;
	int		length;
	char	*src_copy;

	i = 0;
	length = 0;
	while (src[length] != '\0')
		length++;
	src_copy = (char *)malloc((length + 1) * sizeof(char));
	if (src_copy == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		src_copy[i] = src[i];
		i++;
	}
	src_copy[i] = '\0';
	return (src_copy);
}

char	*ft_strchr(const char *s, int c)
{
	char	*aux;

	aux = (char *)s;
	while (*aux)
	{
		if (*aux == (unsigned char) c)
			return (aux);
		aux++;
	}
	if (*aux == (unsigned char) c)
		return (aux);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*str;
	int			counter;
	size_t		i;
	size_t		j;

	counter = 0;
	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	str = (char *) malloc(i + j + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, (i + 1));
	while (j--)
	{
		str[i + counter] = s2[counter];
		counter ++;
	}
	return (str[counter + i] = '\0', str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (len > ft_strlen (s + start))
		len = ft_strlen (s + start);
	str = (char *)malloc ((len +1) * sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	while (++i < len)
	{
		str[i] = s[i + start];
	}
	str[i] = '\0';
	return (str);
}
