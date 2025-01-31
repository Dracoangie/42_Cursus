/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:26:14 by angnavar          #+#    #+#             */
/*   Updated: 2024/08/20 13:26:17 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sign(int *i, int j, char *str)
{
	if ((*str == ' ' || (*str >= 9 && *str <= 13)) && *i == 0)
	{
		return (1);
	}
	else if (*str == '-' && j == 0)
	{
		if (*i == 0)
			*i = -1;
		else
			*i *= -1;
		return (1);
	}
	else if ((*str == '+' || *str == '-' ) && j == 0)
	{
		if (*i == 0)
			*i = 1;
		return (1);
	}
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*str != '\0')
	{
		if (ft_sign(&i, j, str) == 1)
		{
		}
		else if (*str >= '0' && *str <= '9')
		{
			if (i == 0)
				i = 1;
			if (j == 0)
				j = *str - 48;
			else
				j = (j * 10) + (*str - 48);
		}
		else
			return (j * i);
		str++;
	}
	return (j * i);
}
/*
int	main(void)
{
	printf("%i\n", ft_atoi(" \t---+--+1234ab567"));
	printf("%i\n", ft_atoi(" --+1234ab567"));
	printf("%i\n", ft_atoi(" 1234ab567"));
	return(0);
}*/
