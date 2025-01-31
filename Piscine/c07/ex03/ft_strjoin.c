/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 11:25:28 by angnavar          #+#    #+#             */
/*   Updated: 2024/08/27 11:25:30 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	total_length(int size, char **strs, char *sep)
{
	int	length;
	int	sep_length;
	int	i;
	int	j;

	j = 0;
	length = 0;
	sep_length = 0;
	while (sep[sep_length] != '\0')
		sep_length++;
	i = -1;
	while (++i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			length++;
			j++;
		}
		if (i + 1 < size)
			length += sep_length;
	}
	return (length);
}

void	ft_cpystr(int size, char **strs, char *sep, char *str)
{
	int		i;
	int		j;
	int		counter;

	i = -1;
	counter = 0;
	while (++i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			str[counter] = strs[i][j];
			counter++;
			j++;
		}
		j = 0;
		while (i + 1 < size && sep[j] != '\0')
		{
			str[counter] = sep[j];
			counter++;
			j++;
		}
	}
	str[counter] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		length;
	char	*str;

	if (size <= 0)
	{
		str = (char *) malloc(1);
		str[0] = '\0';
		return (str);
	}
	length = total_length (size, strs, sep);
	str = (char *) malloc (length * sizeof (char));
	ft_cpystr(size, strs, sep, str);
	return (str);
}
/*
int	main ()
{
	char	*str[] = {"hola", "mundo", "!"};
	printf("%s\n", ft_strjoin(2, str, " ,"));
	return (0);
}
*/
