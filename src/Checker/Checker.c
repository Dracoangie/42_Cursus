/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:12:42 by angnavar          #+#    #+#             */
/*   Updated: 2025/01/29 12:50:27 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_list	*argv_checker(char ***argv_ref, int i);

t_list	*handle_arg_error(char ***argv_ref, t_list **result)
{
	cleanup_all(*argv_ref, NULL);
	ft_lstclear(result, del_content);
	return (NULL);
}

t_list	*argv_checker(char ***argv_ref, int i)
{
	t_list	*result;
	char	**argv;

	result = NULL;
	argv = *argv_ref;
	while (*argv)
	{
		if (process_argument(argv, &result) == 0)
		{
			return (handle_arg_error(argv_ref, &result));
		}
		argv++;
	}
	if (*argv_ref && i != 0)
		ft_free_split(*argv_ref);
	return (result);
}

int	checker(t_list **nums, char **argv)
{
	char	**argv_copy;

	argv_copy = NULL;
	if (argv[1] && ft_strchr(argv[1], ' ') && !argv[2])
	{
		argv_copy = ft_split(argv[1], ' ');
		if (!argv_copy || !*argv_copy)
			cleanup_all(argv_copy, NULL);
		if (!argv_copy || !*argv_copy)
			return (0);
	}
	else
	{
		argv_copy = ft_split_args(argv + 1);
		if (!argv_copy || !*argv_copy)
			cleanup_all(argv_copy, NULL);
		if (!argv_copy || !*argv_copy)
			return (0);
	}
	*nums = argv_checker(&argv_copy, 0);
	if (!*nums)
		return (0);
	return (ft_free_split(argv_copy), 1);
}
