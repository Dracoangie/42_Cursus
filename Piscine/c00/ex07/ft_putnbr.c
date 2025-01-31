/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:47:37 by angnavar          #+#    #+#             */
/*   Updated: 2024/08/08 13:47:52 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(int b, int nb, int negative)
{
	int	aux[10];
	int	a;
	int	c;

	c = 0;
	a = b;
	while (a-- > 0)
	{
		aux[a] = nb % 10;
		nb = nb / 10;
	}
	if (negative < 0)
		write(1, "-", 1);
	while (a++ < b -1)
	{
		c = aux[a] + '0';
		write(1, &c, 1);
	}
}

void	ft_putnbr(int nb)
{
	int	c;
	int	b;
	int	temp;
	int	negative;

	c = 0;
	negative = 1;
	b = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		negative = -1;
	}
	temp = nb;
	while (temp > 0)
	{
		temp = temp / 10;
		b++;
	}
	ft_print (b, nb, negative);
}
/*
int	main()
{
	ft_putnbr(-2147483647);
	return (0);
}
*/
