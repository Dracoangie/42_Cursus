/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:17:24 by angnavar          #+#    #+#             */
/*   Updated: 2024/08/26 16:17:26 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0')
	{
		if (*s1 > *s2)
			return (1);
		if (*s1 < *s2)
			return (-1);
		s1++;
		s2++;
	}
	if (*s2 != '\0')
		return (-1);
	return (0);
}

void	ft_sort_int_tab(char **tab, int size)
{
	int		i;
	int		j;
	int		min_idx;
	char	*temp;

	i = 0;
	while (i++ < size - 1)
	{
		min_idx = i;
		j = i;
		while (j++ < size - 1)
		{
			if (ft_strcmp (tab[j], tab[min_idx]) < 0)
				min_idx = j;
		}
		temp = tab[min_idx];
		tab[min_idx] = tab[i];
		tab[i] = temp;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc < 2)
		return (0);
	ft_sort_int_tab(argv, argc);
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
