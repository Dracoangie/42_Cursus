/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:51:06 by angnavar          #+#    #+#             */
/*   Updated: 2025/01/28 14:51:14 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static t_node	*create_node(int content)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
	{
		perror("Error al asignar memoria");
		exit(EXIT_FAILURE);
	}
	new_node->content = content;
	new_node->next = NULL;
	new_node->pre = NULL;
	return (new_node);
}

void	init_stack(t_stack *stack)
{
	stack->last = NULL;
}

void	push(t_stack *stack, int content)
{
	t_node	*new_node;
	t_node	*first;

	new_node = create_node(content);
	if (!stack->last)
	{
		new_node->next = new_node;
		new_node->pre = new_node;
		stack->last = new_node;
	}
	else
	{
		first = stack->last->next;
		new_node->next = first;
		new_node->pre = stack->last;
		stack->last->next = new_node;
		first->pre = new_node;
	}
}

int	pop(t_stack *stack)
{
	t_node	*first;
	int		content;
	t_node	*second;

	if (!stack->last)
	{
		ft_printf("Error");
		exit(EXIT_FAILURE);
	}
	first = stack->last->next;
	content = first->content;
	if (first == stack->last)
	{
		free(first);
		stack->last = NULL;
	}
	else
	{
		second = first->next;
		stack->last->next = second;
		second->pre = stack->last;
		free(first);
	}
	return (content);
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next_node;

	if (!stack->last)
		return ;
	current = stack->last->next;
	while (current != stack->last)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	free(current);
	stack->last = NULL;
}
