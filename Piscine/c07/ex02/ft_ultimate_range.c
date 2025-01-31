/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 09:31:48 by angnavar          #+#    #+#             */
/*   Updated: 2024/08/27 09:31:50 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	length;

	i = -1;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	length = max - min;
	*range = (int *)malloc(length * sizeof(int));
	if (*range == NULL)
		return (-1);
	while (++i < length)
	{
		(*range)[i] = min + i;
	}
	return (length);
}

int	main ()
{
	int min = 50;
	int max = 200;
	int *range = NULL;
	
	printf("%i\n", ft_ultimate_range( &range, min, max));
	for (int i = 0; i < max -min; i++)
		printf("%i  ", range[i]);
	return (0);
}

