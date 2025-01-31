/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:47:55 by angnavar          #+#    #+#             */
/*   Updated: 2024/08/13 15:48:01 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <unistd.h>
*/
int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (*str != '\0')
	{
		length++;
		str++;
	}
	return (length);
}
/*
int main(void)
{
    char my_string[] = "Hola!";
    char digit;
    int length = ft_strlen(my_string);
    
    digit = '0' + (length % 10);
    write (1, &digit, 1);
    return 0;
}
*/
