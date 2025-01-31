/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:36:48 by angnavar          #+#    #+#             */
/*   Updated: 2024/08/14 16:36:51 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcapitalize(char *str)
{
	char	auxchar;
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 65 && str[i] <= 90)
		{
			str[i] = str[i] + 32;
		}
		if (str[i] >= 97 && str[i] <= 122)
		{
			auxchar = str[i -1];
			if ((auxchar < '0' || auxchar > '9')
				&& (auxchar < 97 || auxchar > 122)
				&& (auxchar < 65 || auxchar > 90))
				str[i] = str[i] - 32;
		}
		i++;
	}
	return (str);
}
/*
int	main(void)
{
    	char str[] = "hola muNdo!que tal? 0todo bien";
    	
	ft_strcapitalize(str);
	
	printf("%s", str);
	
	return(0);
}
*/
