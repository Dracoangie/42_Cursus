/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 17:32:14 by angnavar          #+#    #+#             */
/*   Updated: 2024/08/13 17:32:17 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <unistd.h>
#include <stdio.h>
*/
void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	min_idx;
	int	temp;

	i = -1;
	while (i++ < size - 1)
	{
		min_idx = i;
		j = i;
		while (j++ < size - 1)
		{
			if (tab[j] < tab[min_idx])
				min_idx = j;
		}
		temp = tab[min_idx];
		tab[min_idx] = tab[i];
		tab[i] = temp;
	}
}
/*
int main()
{
    	int tab[] = {40, -20, 2, -2, -7};
    	int size = sizeof(tab) / sizeof(tab[0]);

    	ft_sort_int_tab(tab, size);
	char digit;
	int i;
    
	for (i = 0; i < size; i++)
	{
		digit = '0' + tab[i];
		printf("%d", tab[i]);
		if (i < size - 1)
		    write(1, " ", 1);
	}

    return 0;
}
*/
