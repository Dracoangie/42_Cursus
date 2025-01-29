/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:00:04 by angnavar          #+#    #+#             */
/*   Updated: 2025/01/28 13:58:58 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ra(t_stack *a)
{
	if (!a->last || a->last->next == a->last)
		return ;
	a->last = a->last->next;
	ft_printf("ra\n");
}

void	rb(t_stack *b)
{
	if (!b->last || b->last->next == b->last)
		return ;
	b->last = b->last->next;
	ft_printf("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	if (!a->last || a->last->next == a->last)
		return ;
	a->last = a->last->next;
	if (!b->last || b->last->next == b->last)
		return ;
	b->last = b->last->next;
	ft_printf("rr\n");
}
