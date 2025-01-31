/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 09:04:15 by angnavar          #+#    #+#             */
/*   Updated: 2024/08/27 09:04:17 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	length;
	int	*range;

	i = -1;
	length = 0;
	if (min >= max)
		return (NULL);
	while (length < max - min)
		length++;
	range = (int *)malloc((length) * sizeof(int));
	while (++i < length)
	{
		range[i] = min + i;
	}
	return (range);
}
/*
int	main ()
{
	int min = 10;
	int max = 20;
	for(int i = 0;i < max - min; i++)
		printf("%i", ft_range(min, max)[i]);
	return (0);
}
*/
