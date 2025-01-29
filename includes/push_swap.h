/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:56:31 by angnavar          #+#    #+#             */
/*   Updated: 2025/01/29 12:34:57 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../includes/ft_printf/ft_printf.h"
# include "../includes/libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

int		checker(t_list **nums, char **argv);
char	**retry(void);
int		process_argument(char **argv, t_list **result);
void	print_content(int content);
int		to_num(const char *nptr, int *result);
void	del_content(int content);
char	**ft_split_args(char **argv);
void	ft_free_split(char **split);
void	cleanup_all(char **argv_copy, t_list *result);
int		is_sorted(t_list *list);
int		has_spaces(char **argv);
int		has_spaces(char **argv);

typedef struct s_node
{
	int				content;
	struct s_node	*next;
	struct s_node	*pre;
}	t_node;

typedef struct s_stack
{
	t_node	*last;
}	t_stack;

void	init_stack(t_stack *stack);
void	push(t_stack *stack, int content);
int		pop(t_stack *stack);
void	print_stack(t_stack *stack);
void	free_stack(t_stack *stack);
void	set_stack(t_stack *a, char **argv);
void	move_list_to_stack(t_list *list, t_stack *stack);
int		stack_length(t_stack *stack);

void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

void	turk_algorithm(t_stack *a, t_stack *b);
void	sort_five(t_stack *a, t_stack *b);
int		is_comparator(t_stack a, int i, int check_greater);
void	fix_a_left(t_stack *a, t_node **aux, int counter, int *organized);
int		count_lasts(t_stack *b, t_node **aux);
int		calculate_b_moves(t_stack b, int value);
int		calculate_b_moves_reversed(t_stack b, int value);
void	update_optimal_position(int i, int b_moves, int min_values[3]);
int		calculate_best_move(t_stack b, t_node *aux);
void	count(t_stack a, t_stack b, int *moves_a, int *moves_b);
void	execute_moves(t_stack *a, t_stack *b, int moves_a, int moves_b);

#endif
