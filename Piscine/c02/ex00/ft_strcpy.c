/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 17:57:28 by angnavar          #+#    #+#             */
/*   Updated: 2024/08/13 17:57:32 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
*/
char	*ft_strcpy(char *dest, char *src)
{
	int	count;

	count = 0;
	while (*src != '\0')
	{
		dest[count] = *src;
		count++;
		src++;
	}
	dest[count] = '\0';
	return (dest);
}
/*
int	main(void)
{
	char dest[] = " ";
    	char src[] = "Hola, mundo!";
    	
	char *a = ft_strcpy(dest,src);
	
	printf("%s", dest);
	
	return(0);
}
*/
