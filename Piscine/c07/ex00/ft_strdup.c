/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:11:55 by angnavar          #+#    #+#             */
/*   Updated: 2024/08/26 18:11:57 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strdup(char *src)
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
/*
int	main(void)
{
	printf("%s", ft_strdup("hola mundo!"));
	return (0);
}
*/
