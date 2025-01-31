/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:26:46 by angnavar          #+#    #+#             */
/*   Updated: 2024/08/14 18:26:49 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	char	*hex_iterator;
	int		i;

	i = 0;
	hex_iterator = "0123456789abcdef";
	while (str[i] != '\0')
	{
		if ((unsigned char)str[i] >= 32 && (unsigned char)str[i] <= 126)
			write(1, &str[i], 1);
		else
		{
			write (1, "\\", 1);
			write (1, &hex_iterator[str[i] / 16], 1);
			write (1, &hex_iterator[str[i] % 16], 1);
		}
		i++;
	}
}
/*
int	main(void)
{
    	char str[] = "Hola\n mundo";
    	
	ft_putstr_non_printable(str);
	
	return(0);
}
*/
