/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:55:46 by angnavar          #+#    #+#             */
/*   Updated: 2024/08/26 15:55:48 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc < 2)
		return (0);
	while (i++ < argc -1)
	{
		while (*argv[i])
		{
			write (1, argv[i], 1);
			argv[i]++;
		}
		write (1, "\n", 1);
	}
	return (0);
}
