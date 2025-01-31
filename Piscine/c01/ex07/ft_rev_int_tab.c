/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:51:57 by angnavar          #+#    #+#             */
/*   Updated: 2024/08/13 15:52:00 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <unistd.h>
*/
void	ft_rev_int_tab(int *tab, int size)
{
	int	temp;
	int	start;
	int	end;

	start = 0;
	end = size - 1;
	while (start < end)
	{
		temp = tab[start];
		tab[start] = tab[end];
		tab[end] = temp;
		start++;
		end--;
	}
}
/*
int	main()
{
    int tab[] = {1, 2, 3, 4, 5};
    int size = 5;

    ft_rev_int_tab(tab, size);
    char digit;
    
    for (int i = 0; i < size; i++)
    {
        digit = '0' + (tab[i] % 10);
        write(1, &digit, 1);
        if (i < size - 1)
            write(1, " ", 1);
    }
    
    return 0;
}
*/
