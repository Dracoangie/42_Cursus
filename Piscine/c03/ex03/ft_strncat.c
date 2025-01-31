/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 19:09:44 by angnavar          #+#    #+#             */
/*   Updated: 2024/08/15 19:09:48 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*aux;

	aux = dest;
	while (*aux != '\0')
	{
		aux++;
	}
	while (nb-- > 0 && *src != '\0')
	{
		*aux = *src;
		aux++;
		src++;
	}
	*aux = '\0';
	return (dest);
}
/*
int	main(void)
{
	char dest[20] = "hola";

	printf("cadena junta: %s\n", ft_strncat(dest," mundo", 4));
	return (0);
}
*/
