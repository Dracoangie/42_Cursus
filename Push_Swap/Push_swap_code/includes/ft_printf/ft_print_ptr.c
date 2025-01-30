/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:16:53 by angnavar          #+#    #+#             */
/*   Updated: 2024/10/24 17:52:13 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_get_ptr(unsigned long ptr)
{
	if (ptr >= 16)
	{
		ft_get_ptr(ptr / 16);
		ft_get_ptr(ptr % 16);
	}
	else
	{
		if (ptr < 10)
			ft_print_chr(ptr + '0');
		else
			ft_print_chr(ptr - 10 + 'a');
	}
}

int	ft_print_ptr(unsigned long ptr)
{
	int	size;

	size = 0;
	if (ptr == 0)
		return (ft_print_str("(nil)"));
	size += ft_print_str("0x");
	ft_get_ptr(ptr);
	size += ft_ptrlen(ptr);
	return (size);
}
