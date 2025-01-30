/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate_reverse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:01:43 by angnavar          #+#    #+#             */
/*   Updated: 2025/01/28 13:59:45 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rra(t_stack *a)
{
	if (!a->last || a->last->next == a->last)
		return ;
	a->last = a->last->pre;
	ft_printf("rra\n");
}

void	rrb(t_stack *b)
{
	if (!b->last || b->last->next == b->last)
		return ;
	b->last = b->last->pre;
	ft_printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	if (!a->last || a->last->next == a->last)
		return ;
	a->last = a->last->pre;
	if (!b->last || b->last->next == b->last)
		return ;
	b->last = b->last->pre;
	ft_printf("rrr\n");
}
