/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:12:03 by angnavar          #+#    #+#             */
/*   Updated: 2024/08/26 16:12:07 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;

	i = argc;
	if (argc < 2)
		return (0);
	while (i-- > 1)
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
