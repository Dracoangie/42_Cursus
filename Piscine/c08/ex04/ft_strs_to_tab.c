/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:51:07 by angnavar          #+#    #+#             */
/*   Updated: 2024/08/28 10:51:09 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "ft_stock_str.h"

char	*ft_strdup(char *src)
{
	int		i;
	char	*dup;

	i = 0;
	while (src[i])
		i++;
	dup = (char *)malloc((i + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_free_tab(t_stock_str *array, int n)
{
	while (n >= 0)
		free(array[n--].copy);
	free(array);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*array;

	array = (t_stock_str *)malloc ((ac + 1) * sizeof (t_stock_str));
	if (!array)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		array[i].size = ft_strlen(av[i]);
		array[i].str = av[i];
		array[i].copy = ft_strdup(av[i]);
		if (!array[i].copy)
			return (ft_free_tab(array, i - 1), NULL);
		i++;
	}
	array[i].str = 0;
	return (array);
}
/*
int	main(void)
{
	//t_stock_str	*stock;
	char *src[] = {"hola ", "mundo ", "!"};
	int i = -1;

	//ft_strs_to_tab(3, src);
	//printf("%s", ft_strs_to_tab(3, src)->str);
	while(++i < 3)
	{
		printf("%s", ft_strs_to_tab(3, src)[i].str);
	}
	return (0);
}
*/
