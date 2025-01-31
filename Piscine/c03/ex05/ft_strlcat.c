/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:09:30 by angnavar          #+#    #+#             */
/*   Updated: 2024/08/19 18:09:33 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	j;
	unsigned int	i;
	unsigned int	a;

	j = 0;
	i = 0;
	a = 0;
	while (dest[j] != '\0')
		j++;
	while (src[i] != '\0')
		i++;
	if (size <= j)
		return (size + j);
	while (src[a] != '\0' && i + a < size -1)
	{
		dest[j + a] = src[a];
		a++;
	}
	dest[j + a] = '\0';
	return (i + j);
}

int	main(void)
{
	char*	print = "hola mundo! ";
	char	check[40] = "hello World!";
	printf("%i\n", ft_strlcat(check, print, 20));
	printf("%s\n", check);
	return(0);
}

