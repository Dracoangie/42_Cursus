/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:47:37 by angnavar          #+#    #+#             */
/*   Updated: 2024/08/08 13:47:52 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> 

void	ft_print_reverse_alphabet(void)
{
	char	counter;

	counter = 'z';
	while (counter > 'a' - 1)
	{
		write(1, &counter, 1);
		counter--;
	}
}
/*
int	main(void)
{
	ft_print_alphabet();
	return(0);
}
*/
