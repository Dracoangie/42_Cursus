/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:36:10 by angnavar          #+#    #+#             */
/*   Updated: 2025/01/29 12:34:27 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	del_content(int content)
{
	if (content)
		return ;
}

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

char	**ft_duplicate_args(char **argv)
{
	int		i;
	int		count;
	char	**copy;

	i = -1;
	count = 0;
	while (argv[count])
		count++;
	copy = (char **)malloc((count + 1) * sizeof(char *));
	if (!copy)
		return (NULL);
	while (++i < count)
	{
		copy[i] = ft_strdup(argv[i]);
		if (!copy[i])
		{
			while (i > 0)
				free(copy[--i]);
			free(copy);
			return (NULL);
		}
	}
	copy[count] = NULL;
	return (copy);
}

char	**ft_split_args(char **argv)
{
	if (!argv || !argv[0] || has_spaces(argv))
		return (NULL);
	if (argv[1] && ft_strchr(argv[1], ' '))
		return (ft_split(argv[1], ' '));
	return (ft_duplicate_args(argv));
}

void	cleanup_all(char **argv_copy, t_list *result)
{
	if (argv_copy)
		ft_free_split(argv_copy);
	if (result)
		ft_lstclear(&result, del_content);
}
