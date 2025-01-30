/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:05:07 by angnavar          #+#    #+#             */
/*   Updated: 2025/01/29 12:33:32 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	calculate_and_move(t_stack *a, t_stack *b)
{
	int	moves_a;
	int	moves_b;

	moves_a = 0;
	moves_b = 0;
	count(*a, *b, &moves_a, &moves_b);
	execute_moves(a, b, moves_a, moves_b);
	pb(a, b);
	if (is_comparator(*b, b->last->next->content, 0))
		rb(b);
}

void	reorder_b(t_node *aux, t_stack *b)
{
	int	b_reverse;
	int	b_int;

	b_reverse = 0;
	b_int = 0;
	aux = b->last;
	while (!is_comparator(*b, aux->content, 0))
	{
		aux = aux->pre;
		b_reverse++;
	}
	aux = b->last->next;
	while (!is_comparator(*b, aux->content, 1))
	{
		aux = aux->next;
		b_int++;
	}
	if (b_reverse < b_int)
	{
		while (!is_comparator(*b, b->last->content, 0))
			rrb(b);
		return ;
	}
	while (!is_comparator(*b, b->last->next->content, 1))
		rb(b);
}

void	fix_last(t_node *aux, t_stack *a, int lasts, int *organized)
{
	while (!is_comparator(*a, a->last->content, 1))
		rra(a);
	if (is_comparator(*a, a->last->next->content, 0))
		return ;
	while (aux->content < a->last->next->content)
		fix_a_left(a, &aux, lasts, organized);
}

void	b_to_a(t_node *aux, t_stack *a, t_stack *b)
{
	int	i;
	int	lasts;
	int	organized;
	int	counter;

	i = 0;
	counter = 0;
	aux = a->last;
	organized = 0;
	lasts = count_lasts(b, &aux);
	while (stack_length(b) > 1)
	{
		pa(a, b);
		while (i < 3)
		{
			if (aux->content < a->last->next->content
				&& aux->content > b->last->next->content)
				fix_a_left(a, &aux, lasts, &organized);
			i++;
		}
		i = organized;
	}
	pa(a, b);
	fix_last(aux, a, lasts, &organized);
}

void	turk_algorithm(t_stack *a, t_stack *b)
{
	t_node	*aux;

	aux = NULL;
	pb(a, b);
	pb(a, b);
	if (b->last->next->content > b->last->content)
		rb(b);
	while (stack_length(a) > 3)
	{
		calculate_and_move(a, b);
	}
	sort_five(a, b);
	reorder_b(aux, b);
	b_to_a(aux, a, b);
}

	/*printf("Stack A despues del algoritmo: \n");
	print_stack(a);
	printf("Stack B despues del algoritmo: \n");
	print_stack(b);
	printf("Stack A despues del algoritmo: \n");
	print_stack(a);
	printf("Stack B despues del algoritmo: \n");
	print_stack(b);*/