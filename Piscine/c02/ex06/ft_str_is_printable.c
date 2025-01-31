/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:44:09 by angnavar          #+#    #+#             */
/*   Updated: 2024/08/14 15:44:12 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	while (*str != '\0')
	{
		if (*str >= 0 && *str <= 31)
		{
			return (0);
		}
		str++;
	}
	return (1);
}
/*
int	main(void)
{
    	char str[] = "Hola\n Mundo";
    	
	int a = ft_str_is_printable(str);
	char aux = a + '0';
	
	printf("%s", &aux);
	
	return(0);
}
*/
