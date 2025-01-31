/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:47:37 by angnavar          #+#    #+#             */
/*   Updated: 2024/08/08 13:47:52 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(int a, int n, int counter[10])
{
	int	b;

	b = 0;
	a = n;
	while (a-- > 0)
	{
		b = counter[a] + '0';
		write (1, &b, 1);
	}
	write (1, ", ", 2);
}

void	ft_combn(int c, int a, int n)
{
	int	counter[10];

	while (c++ < n)
		counter[c] = 0;
	while (counter[n -1] < 10 - n)
	{
		c = -1;
		while (c++ < n)
		{
			if (counter[c] < 9 - c)
			{
				counter[c]++;
				a = -1;
				while (a++ < c)
				{
					counter[a] = counter[c] + c - a;
				}
				c = 10;
			}
		}
		ft_print (a, n, counter);
	}
}

void	ft_print_combn(int n)
{
	int	a;
	int	c;

	a = 0;
	if (n < 0 || n > 10)
		return ;
	c = -1;
	ft_combn(c, a, n);
}
/*
int	main(void)
{
	ft_print_combn(3);
	return(0);
}
*/
