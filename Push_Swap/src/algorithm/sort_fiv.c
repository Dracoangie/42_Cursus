/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_fiv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:00:04 by angnavar          #+#    #+#             */
/*   Updated: 2025/01/28 14:10:33 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	find_smallest_position(t_stack *a)
{
	t_node	*current;
	int		smallest;
	int		position;
	int		i;

	current = a->last->next;
	smallest = current->content;
	position = 0;
	i = 0;
	while (1)
	{
		if (current->content < smallest)
		{
			smallest = current->content;
			position = i;
		}
		if (current == a->last)
			break ;
		current = current->next;
		i++;
	}
	return (position);
}

void	push_smallest_to_b(t_stack *a, t_stack *b)
{
	int	position;

	position = find_smallest_position(a);
	if (position <= stack_length(a) / 2)
	{
		while (position-- > 0)
			ra(a);
	}
	else
	{
		position = stack_length(a) - position;
		while (position-- > 0)
			rra(a);
	}
	pb(a, b);
}

void	execute_sort_three(t_stack *stack, int first, int second, int third)
{
	if (first < second && second < third)
		return ;
	if (first > second && first > third)
	{
		ra(stack);
		if (second > third)
			sa(stack);
	}
	else if (second > first && second > third)
	{
		rra(stack);
		if (first < third)
			sa(stack);
	}
	else
	{
		if (first > second)
			sa(stack);
	}
}

void	sort_three(t_stack *stack)
{
	int	first;
	int	second;
	int	third;

	if (!stack || !stack->last)
		return ;
	first = stack->last->next->content;
	second = stack->last->next->next->content;
	third = stack->last->content;
	execute_sort_three(stack, first, second, third);
}

void	sort_five(t_stack *a, t_stack *b)
{
	int	size;

	size = stack_length(a);
	if (size == 3)
	{
		sort_three(a);
		return ;
	}
	push_smallest_to_b(a, b);
	if (size == 5)
		push_smallest_to_b(a, b);
	sort_three(a);
	pa(a, b);
	if (size == 5)
		pa(a, b);
}
