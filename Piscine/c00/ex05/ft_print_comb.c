/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:47:37 by angnavar          #+#    #+#             */
/*   Updated: 2024/08/08 13:47:52 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_numbers(int d, int e, int f)
{
	int	x;

	if (f != e && f != d && e != d)
	{
		x = d + '0';
		write (1, &x, 1);
		x = e + '0';
		write (1, &x, 1);
		x = f + '0';
		write (1, &x, 1);
		if (d < 7 || e < 8 || f < 9)
			write(1, ", ", 2);
	}
}

void	ft_print_comb(void)
{
	int	a;
	int	b;
	int	c;

	a = 0;
	b = 1;
	c = 2;
	while (a < 8)
	{
		while (b < 9)
		{
			while (c < 10)
			{
				print_numbers (a, b, c);
				c = c + 1;
			}
			b = b + 1;
			c = b;
		}
		a = a + 1;
		b = a;
	}
}
/*
int	main()
{
	ft_print_comb();
	return (0);
}
*/
