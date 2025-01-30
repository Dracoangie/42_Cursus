/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Checker_Helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:12:42 by angnavar          #+#    #+#             */
/*   Updated: 2025/01/29 12:34:41 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	print_content(int content)
{
	ft_printf("%d\n", content);
}

int	to_num(const char *nptr, int *result)
{
	long	temp_result;
	int		sign;
	int		has_num;

	*result = 0;
	temp_result = 0;
	sign = 1;
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		temp_result = temp_result * 10 + (*nptr - '0');
		nptr++;
		has_num = 1;
	}
	if (*nptr != '\0' || has_num != 1)
		return (0);
	if ((sign == 1 && temp_result > 2147483647)
		|| (sign == -1 && - temp_result < -2147483648))
		return (0);
	*result = (int)(temp_result * sign);
	return (1);
}

int	process_argument(char **argv, t_list **result)
{
	int		num;
	t_list	*aux;

	aux = *result;
	if (to_num(*argv, &num) == 1)
	{
		while (aux)
		{
			if (num != aux->content)
				aux = aux->next;
			else
				return (0);
		}
		if (!*result)
			*result = ft_lstnew(num);
		else
			ft_lstadd_front(result, ft_lstnew(num));
		return (1);
	}
	else
		return (0);
}

int	is_sorted(t_list *list)
{
	if (!list)
		return (1);
	while (list->next)
	{
		if (list->content < list->next->content)
			return (0);
		list = list->next;
	}
	return (1);
}

int	has_spaces(char **argv)
{
	while (*argv)
	{
		if (ft_strchr(*argv, ' '))
			return (1);
		argv++;
	}
	return (0);
}
