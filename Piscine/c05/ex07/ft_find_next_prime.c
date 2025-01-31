/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:05:09 by angnavar          #+#    #+#             */
/*   Updated: 2024/08/26 14:05:11 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_find_next_prime(int nb)
{
	int	prime;
	int	found;
	int	i;

	found = 0;
	prime = nb;
	i = 1;
	if (nb < 2)
		return (2);
	while (found != 1)
	{
		while (++i < prime)
		{
			if (prime % i == 0)
				found = -1;
		}
		i = 1;
		if (found == 0)
			return (prime);
		else
			found = 0;
		prime++;
	}
	return (0);
}
/*
int	main()
{
	printf("%d\n", ft_find_next_prime(6));
	printf("%d\n", ft_find_next_prime(42));
	printf("%d\n", ft_find_next_prime(-4));
	printf("%d\n", ft_find_next_prime(123));
	printf("%d\n", ft_find_next_prime(3));
	printf("%d\n", ft_find_next_prime(50));
	printf("%d\n", ft_find_next_prime(20));
	printf("%d\n", ft_find_next_prime(1));
	return 0;
}
*/
