/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:16:53 by angnavar          #+#    #+#             */
/*   Updated: 2025/02/03 15:24:44 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptrlen(unsigned long ptr)
{
	int	len;

	len = 0;
	while (ptr > 0)
	{
		len++;
		ptr /= 16;
	}
	return (len);
}
