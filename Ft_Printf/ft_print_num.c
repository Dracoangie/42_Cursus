/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:16:53 by angnavar          #+#    #+#             */
/*   Updated: 2024/10/24 17:57:52 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexnum(unsigned int unum, int menor)
{
	int	size;

	size = 0;
	if (unum >= 16)
	{
		size += ft_print_hexnum(unum / 16, menor);
		size += ft_print_hexnum(unum % 16, menor);
	}
	else
	{
		if (unum < 10)
			ft_print_chr(unum + '0');
		else
			ft_print_chr(unum - 10 + 'a' - menor);
		size++;
	}
	return (size);
}

int	ft_print_unum(unsigned int unum)
{
	int	size;

	size = 0;
	if (unum == 0)
		size += ft_print_chr('0');
	else
	{
		if (unum / 10 != 0)
			ft_print_unum(unum / 10);
		ft_print_chr((unum % 10) + '0');
		while (unum > 0)
		{
			unum /= 10;
			size++;
		}
	}
	return (size);
}

int	ft_print_num(int num)
{
	int	size;

	size = 0;
	if (num == 0)
		return (ft_print_chr('0'));
	else if (num == -2147483648)
		return (ft_print_str("-2147483648"));
	else if (num < 0)
	{
		size += ft_print_chr('-');
		num = -num;
	}
	size += ft_print_unum((unsigned int)num);
	return (size);
}
