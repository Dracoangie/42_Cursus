/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:47:37 by angnavar          #+#    #+#             */
/*   Updated: 2024/08/08 13:47:52 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	int	i;
	int	a;

	i = -1;
	while (i++ < 9)
	{
		a = i + '0';
		write(1, &a, 1);
	}
}
/*
int	main(void)
{
	ft_print_alphabet();
	return (0);
}
*/
