/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:30:20 by angnavar          #+#    #+#             */
/*   Updated: 2025/02/02 23:45:49 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

float	abs_float(float x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;
	unsigned int	len;

	i = -1;
	len = ft_strlen(s1);
	while (++i < len)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (s1[i] == '\0' && s2[i] != '\0')
			return (1);
	}
	return (0);
}

void	put_pixel(t_data *data, int x, int y, int color)
{
	int	index;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		index = (y * data->img.line_len) + (x * (data->img.bits_per_pixel / 8));
		*(int *)(data->img.img_pixels_ptr + index) = color;
	}
}

int	set_color(int iter, int color_table[MAX_ITER])
{
	if (iter == MAX_ITER)
		return (0);
	return (color_table[iter]);
}

void	draw_fractal_row(t_data *data, int y, int color_table[MAX_ITER])
{
	int		x;
	int		iter;
	float	scaled_x;
	float	scaled_y;

	x = 0;
	scaled_y = (y - HEIGHT / 2.0) * (1.0 / (0.5 * data->zoom * HEIGHT))
		+ data->move_y;
	while (x < WIDTH)
	{
		scaled_x = (x - WIDTH / 2.0) * (1.0 / (0.5 * data->zoom * WIDTH))
			+ data->move_x;
		if (data->fractal == 0)
			iter = mandelbrot(scaled_x, scaled_y, data->julia_re,
					data->julia_im);
		else if (data->fractal == 1)
			iter = julia(scaled_x, scaled_y);
		else if (data->fractal == 2)
			iter = burning_ship(scaled_x, scaled_y);
		else if (data->fractal == 3)
			iter = tricorn(scaled_x, scaled_y);
		put_pixel(data, x, y, set_color(iter, color_table));
		x++;
	}
}
