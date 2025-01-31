/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:36:38 by angnavar          #+#    #+#             */
/*   Updated: 2024/08/18 19:09:19 by jesusrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// se enfoca en ver si cada linea de input coincide con el output dado;
int	check_up(int output[4][4], int input, int col, int size)
{
	int	max_seen;
	int	seen;
	int	i;

	max_seen = 0;
	seen = 0;
	i = 0;
	while (i < size)
	{
		if (output[i][col] > max_seen)
		{
			max_seen = output[i][col];
			seen++;
		}
		i++;
	}
	if (input == seen)
		return (1);
	else
		return (0);
}

// se enfoca en ver si cada linea de input coincide con el output dado;
int	check_right(int output[4][4], int input, int row, int size)
{
	int	max_seen;
	int	seen;
	int	i;

	max_seen = 0;
	seen = 0;
	i = size - 1;
	while (i >= 0)
	{
		if (output[row][i] > max_seen)
		{
			max_seen = output[row][i];
			seen++;
		}
		i--;
	}
	if (input == seen)
		return (1);
	else
		return (0);
}

// se enfoca en ver si cada linea de input coincide con el output dado;
int	check_down(int output[4][4], int input, int col, int size)
{
	int	max_seen;
	int	seen;
	int	i;

	max_seen = 0;
	seen = 0;
	i = size - 1;
	while (i >= 0)
	{
		if (output[i][col] > max_seen)
		{
			max_seen = output[i][col];
			seen++;
		}
		i--;
	}
	if (input == seen)
		return (1);
	else
		return (0);
}

// se enfoca en ver si cada linea de input coincide con el output dado;
int	check_left(int output[4][4], int input, int row, int size)
{
	int	max_seen;
	int	seen;
	int	i;

	max_seen = 0;
	seen = 0;
	i = 0;
	while (i < size)
	{
		if (output[row][i] > max_seen)
		{
			max_seen = output[row][i];
			seen++;
		}
		i++;
	}
	if (input == seen)
		return (1);
	else
		return (0);
}
