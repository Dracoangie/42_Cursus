/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm_helper.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:12:14 by angnavar          #+#    #+#             */
/*   Updated: 2025/01/29 12:20:02 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_comparator(t_stack a, int i, int check_greater)
{
	t_node	*aux;

	if (!a.last)
		return (1);
	aux = a.last->next;
	while (1)
	{
		if ((check_greater && i < aux->content) || (!check_greater
				&& i > aux->content))
			return (0);
		aux = aux->next;
		if (aux == a.last->next)
			break ;
	}
	return (1);
}

void	fix_a_left(t_stack *a, t_node **aux, int counter, int *organized)
{
	*aux = (*aux)->pre;
	rra(a);
	if (counter == 1)
	{
		rra(a);
		sa(a);
		ra(a);
	}
	if (counter == 2)
	{
		rra(a);
		rra(a);
		sa(a);
		ra(a);
		sa(a);
		ra(a);
	}
	(*organized)++;
}

int	count_lasts(t_stack *b, t_node **aux)
{
	int	lasts;

	lasts = 0;
	while (is_comparator(*b, (*aux)->content, 1) && lasts < 3)
	{
		*aux = (*aux)->pre;
		lasts++;
	}
	return (lasts);
}

void	count(t_stack a, t_stack b, int *moves_a, int *moves_b)
{
	int		i;
	int		min_values[3];
	t_node	*aux;

	min_values[0] = -1;
	min_values[1] = -1;
	min_values[2] = 0;
	aux = a.last->next;
	i = -1;
	while (++i < stack_length(&a))
	{
		update_optimal_position(i, calculate_best_move(b, aux), min_values);
		if (aux == a.last)
			break ;
		aux = aux->next;
	}
	*moves_a = min_values[1];
	*moves_b = min_values[2];
}

void	execute_moves(t_stack *a, t_stack *b, int moves_a, int moves_b)
{
	while (moves_a > 0 && moves_b > 0)
	{
		rr(a, b);
		moves_a--;
		moves_b--;
	}
	if (moves_b > 0)
	{
		while (moves_b-- > 0)
			rb(b);
	}
	else
	{
		while (moves_b++ < 0)
			rrb(b);
	}
	while (moves_a-- > 0)
		ra(a);
}
