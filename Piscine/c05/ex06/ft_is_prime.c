/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 12:25:39 by angnavar          #+#    #+#             */
/*   Updated: 2024/08/26 12:25:42 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	prime;

	prime = 1;
	if (nb < 2)
		return (0);
	while (++prime < nb)
	{
		if (nb % prime == 0)
			return (0);
	}
	return (1);
}
/*
int	main()
{
	printf("%d\n", ft_is_prime(7));
	printf("%d\n", ft_is_prime(2));
	printf("%d\n", ft_is_prime(-4));
	printf("%d\n", ft_is_prime(44));
	return 0;
}
*/
