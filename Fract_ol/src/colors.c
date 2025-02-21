/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:34:01 by angnavar          #+#    #+#             */
/*   Updated: 2025/02/10 18:00:57 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

void	generate_color_table(int iter, int *color_table, int colortype)
{
	int		g;
	double	t;
	int		r;
	int		i;

	i = 0;
	g = 0;
	while (i < iter)
	{
		t = (double)i / iter;
		r = (int)(sin(t * 3.14) * 255);
		if (r > 100)
			g = r / 5;
		if (colortype == 0)
			color_table[i] = (r << 16) | (g << 8) | 0;
		if (colortype == 1)
			color_table[i] = (0 << 16) | (r << 8) | g;
		if (colortype == 2)
			color_table[i] = (0 << 16) | (g << 8) | r;
		i++;
	}
}

void	generate_color_table_rd(int iter, int *color_table)
{
	double	t;
	int		r;
	int		g;
	int		i;

	i = 0;
	while (i < iter)
	{
		t = (double)i / iter;
		r = (int)((sin(t * 3.14 * 10) * 0.5 + 0.5) * 255);
		g = (int)((cos(t * 3.14 * 15) * 0.5 + 0.5) * 255);
		color_table[i] = (r << 16) | (g << 8) | (i * 73) % 256;
		i++;
	}
}
