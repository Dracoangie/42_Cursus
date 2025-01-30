/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_swap_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:00:04 by angnavar          #+#    #+#             */
/*   Updated: 2025/01/28 13:59:32 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sa(t_stack *a)
{
	t_node	*first;
	t_node	*second;

	if (!a->last || a->last->next == a->last)
		return ;
	first = a->last->next;
	second = first->next;
	first->next = second->next;
	second->next->pre = first;
	second->pre = a->last;
	second->next = first;
	first->pre = second;
	a->last->next = second;
	ft_printf("sa\n");
}

void	sb(t_stack *b)
{
	t_node	*first;
	t_node	*second;

	if (!b->last || b->last->next == b->last)
		return ;
	first = b->last->next;
	second = first->next;
	first->next = second->next;
	second->next->pre = first;
	second->pre = b->last;
	second->next = first;
	first->pre = second;
	b->last->next = second;
	ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	t_node	*first;
	t_node	*second;

	if (!a->last || a->last->next == a->last)
		return ;
	first = a->last->next;
	second = first->next;
	first->next = second->next;
	second->next->pre = first;
	second->pre = a->last;
	second->next = first;
	first->pre = second;
	a->last->next = second;
	if (!b->last || b->last->next == b->last)
		return ;
	first = b->last->next;
	second = first->next;
	first->next = second->next;
	second->next->pre = first;
	second->pre = b->last;
	second->next = first;
	first->pre = second;
	b->last->next = second;
	ft_printf("ss\n");
}

void	pa(t_stack *a, t_stack *b)
{
	if (!b->last)
		return ;
	push(a, pop(b));
	ft_printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	if (!a->last)
		return ;
	push(b, pop(a));
	ft_printf("pb\n");
}
