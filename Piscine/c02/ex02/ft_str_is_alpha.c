/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 14:44:46 by angnavar          #+#    #+#             */
/*   Updated: 2024/08/14 14:44:51 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
*/
int	ft_str_is_alpha(char *str)
{
	while (*str != '\0')
	{
		if (*str < 'A' || *str > 'Z')
		{
			if (*str < 'a' || *str > 'z')
			{
				return (0);
			}
		}
		str++;
	}
	return (1);
}
/*
int	main(void)
{
    	char str[] = "Hol@ Mandoz";
    	
	int a = ft_str_is_alpha(str);
	char aux = a + '0';
	
	printf("%s", &aux);
	
	return(0);
}
*/
