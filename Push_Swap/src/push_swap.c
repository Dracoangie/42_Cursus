/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:12:42 by angnavar          #+#    #+#             */
/*   Updated: 2025/01/29 12:35:13 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc <= 0)
		return (0);
	a = (t_stack *)malloc(sizeof(t_stack));
	set_stack(a, argv);
	if (!a || !a->last)
		return (free(a), 0);
	b = (t_stack *)malloc(sizeof(t_stack));
	init_stack(b);
	if (stack_length(a) > 5)
		turk_algorithm(a, b);
	else
		sort_five(a, b);
	free_stack(a);
	free(a);
	free_stack(b);
	free(b);
	return (0);
}
