/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 14:23:54 by angnavar          #+#    #+#             */
/*   Updated: 2024/08/18 19:00:49 by mnjie-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	check_up(int output[4][4], int input, int col, int size);
int	check_right(int output[4][4], int input, int col, int size);
int	check_down(int output[4][4], int input, int col, int size);
int	check_left(int output[4][4], int input, int col, int size);

// mira que el tablero sea valido, 
// checkeando lo que tiene el input con el output;  
int	valid_output(int output[4][4], int input[4][4], int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (check_up(output, input [0][i], i, size) == 0
			|| check_down(output, input [1][i], i, size) == 0
			|| check_left(output, input [2][i], i, size) == 0
			|| check_right(output, input [3][i], i, size) == 0)
			return (0);
		i++;
	}
	return (1);
}

// mira que no haya el mismo número en su fila y columna;
int	placeable(int output[4][4], int row_col[2], int i, int size)
{
	int	j;

	j = 0;
	while (j < size)
	{
		if (output[row_col[0]][j] == i || output[j][row_col[1]] == i)
			return (0);
		j++;
	}
	return (1);
}

// funcion recursiva que tiene el core del programa,
// se encarga de ver si el programa ha llegado a una solucion,
// si no llega a una solución devuelve un 0, sino un 1;
int	solution(int output[4][4], int input[4][4], int size, int pos)
{
	int	row_col[2];
	int	i;

	row_col[0] =  pos / size;
	row_col[1] = pos % size;
	i = 1;
	if (pos == size * size)
		return (valid_output(output, input, size));
	if (output[row_col[0]][row_col[1]] != 0)
		return (solution(output, input, size, pos + 1));
	while (i <= size)
	{
		if (placeable(output, row_col, i, size))
		{
			output[row_col[0]][row_col[1]] = i;
			if (solution(output, input, size, pos + 1))
				return (1);
			output[row_col[0]][row_col[1]] = 0;
		}
		i++;
	}
	return (0);
}
