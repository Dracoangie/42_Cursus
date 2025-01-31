/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:36:01 by angnavar          #+#    #+#             */
/*   Updated: 2024/08/18 18:36:28 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	solution(int output[4][4], int input[4][4], int size, int pos);

int	correct_input(char *argv, int input[4][4])
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (++i < 4)
	{
		while (j < 4)
		{
			if (*argv >= '0' && *argv <= '4')
			{
				input[i][j] = *argv - 48;
				j++;
			}
			else if (*argv != ' ')
				return (0);
			argv++;
		}
		j = 0;
	}
	if (*argv != '\0')
		return (0);
	return (1);
}

void	create_output(int output[4][4])
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < 4)
	{
		while (++j < 4)
		{
			output[i][j] = 0;
		}
		j = -1;
	}
}

void	print_solution(int output[4][4])
{
	int	i;
	int	j;
	int	a;

	i = -1;
	j = -1;
	while (++i < 4)
	{
		while (++j < 4)
		{
			a = output[i][j] + '0';
			write(1, &a, 1);
			if (j < 3)
				write(1, " ", 1);
		}
		write (1, "\n", 1);
		j = -1;
	}
}

int	main(int argc, char *argv[])
{
	int	input[4][4];
	int	output[4][4];
	int	a;

	a = argc;
	create_output (output);
	if (correct_input (argv[1], input) == 0)
		write (1, "Error\n", 6);
	else
	{
		if (solution (output, input, 4, 0))
			print_solution (output);
		else
			write (1, "Error\n", 6);
	}
	return (0);
}
