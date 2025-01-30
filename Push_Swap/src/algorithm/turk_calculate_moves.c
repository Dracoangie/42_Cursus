/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_calculate_moves.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:42:25 by angnavar          #+#    #+#             */
/*   Updated: 2025/01/28 15:03:30 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	calculate_b_moves(t_stack b, int value)
{
	t_node	*b_aux;
	int		b_moves;

	b_moves = 0;
	b_aux = b.last->next;
	if (is_comparator(b, value, 1) || is_comparator(b, value, 0))
	{
		while (!is_comparator(b, b_aux->content, 1))
		{
			b_aux = b_aux->next;
			b_moves++;
		}
	}
	else
	{
		while (!(value > b_aux->content && value < b_aux->pre->content))
		{
			b_aux = b_aux->next;
			b_moves++;
		}
	}
	return (b_moves);
}

int	calculate_b_moves_reversed(t_stack b, int value)
{
	t_node	*b_aux;
	int		b_moves;

	b_moves = 0;
	b_aux = b.last->next;
	if (is_comparator(b, value, 1) || is_comparator(b, value, 0))
	{
		while (!is_comparator(b, b_aux->pre->content, 0))
		{
			b_aux = b_aux->pre;
			b_moves++;
		}
	}
	else
	{
		while (!(value > b_aux->content && value < b_aux->pre->content))
		{
			b_aux = b_aux->pre;
			b_moves++;
		}
	}
	return (b_moves);
}

void	update_optimal_position(int i, int b_moves, int min_values[3])
{
	int	count;

	if (b_moves >= 0)
		count = i + b_moves;
	else
		count = i + (-b_moves);
	if (min_values[0] == -1 || count < min_values[0])
	{
		min_values[0] = count;
		min_values[1] = i;
		min_values[2] = b_moves;
	}
}

int	calculate_best_move(t_stack b, t_node *aux)
{
	int	b_moves;
	int	b_moves_reverse;
	int	best_b_moves;

	b_moves = calculate_b_moves(b, aux->content);
	b_moves_reverse = calculate_b_moves_reversed(b, aux->content);
	if (b_moves <= b_moves_reverse)
		best_b_moves = b_moves;
	else
		best_b_moves = -b_moves_reverse;
	return (best_b_moves);
}

