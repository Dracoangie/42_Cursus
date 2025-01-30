/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:19:13 by angnavar          #+#    #+#             */
/*   Updated: 2025/01/29 12:31:06 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	move_list_to_stack(t_list *list, t_stack *stack)
{
	t_list	*temp;

	while (list)
	{
		push(stack, list->content);
		temp = list;
		list = list->next;
		free(temp);
	}
}

void	set_stack(t_stack *a, char **argv)
{
	t_list	*list;

	if (!argv[1])
		return ;
	if (!checker(&list, argv))
	{
		write(2, "Error\n", 6);
		free(a);
		exit(EXIT_FAILURE);
	}
	init_stack(a);
	if (!is_sorted(list))
		move_list_to_stack(list, a);
	else
		ft_lstclear(&list, del_content);
}

void	print_stack(t_stack *stack)
{
	t_node	*current;

	if (!stack->last)
		return ;
	current = stack->last->next;
	while (1)
	{
		ft_printf("%d\n", current->content);
		if (current == stack->last)
			break ;
		current = current->next;
	}
}

int	stack_length(t_stack *stack)
{
	int		length;
	t_node	*current;

	length = 0;
	if (!stack || !stack->last)
		return (0);
	current = stack->last->next;
	while (current != stack->last->next || length == 0)
	{
		length++;
		current = current->next;
	}
	return (length);
}
