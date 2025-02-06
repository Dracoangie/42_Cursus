/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:32:19 by angnavar          #+#    #+#             */
/*   Updated: 2025/02/02 23:07:04 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

int	julia(float cr, float ci)
{
	float	zr;
	float	zi;
	int		iter;
	float	zr2;
	float	zi2;

	zr = 0;
	zi = 0;
	iter = 0;
	while ((zr * zr + zi * zi) < 16 && iter < MAX_ITER)
	{
		zr2 = zr * zr;
		zi2 = zi * zi;
		if (zr2 + zi2 > 16)
			break ;
		zi = 2 * zr * zi + ci;
		zr = zr2 - zi2 + cr;
		iter++;
	}
	return (iter);
}

int	mandelbrot(float zr, float zi, float cr, float ci)
{
	int		iter;
	float	esc_rad;
	float	zr2;
	float	zi2;

	iter = 0;
	esc_rad = 16;
	while ((zr * zr + zi * zi) < esc_rad && iter < MAX_ITER)
	{
		zr2 = zr * zr;
		zi2 = zi * zi;
		if (zr2 + zi2 > esc_rad)
			break ;
		zi = 2 * zr * zi + ci;
		zr = zr2 - zi2 + cr;
		iter++;
	}
	return (iter);
}

int	burning_ship(float cr, float ci)
{
	float	zr;
	float	zi;
	int		iter;
	float	zr2;
	float	zi2;

	zr = 0;
	zi = 0;
	iter = 0;
	while ((zr * zr + zi * zi) < ESCAPE_RADIUS && iter < MAX_ITER)
	{
		zr2 = zr * zr;
		zi2 = zi * zi;
		if (zr2 + zi2 > ESCAPE_RADIUS)
			break ;
		zi = abs_float(2 * zr * zi) + ci;
		zr = zr2 - zi2 + cr;
		iter++;
	}
	return (iter);
}

int	tricorn(float cr, float ci)
{
	float	zr;
	float	zi;
	int		iter;
	float	zr2;
	float	zi2;

	zr = 0;
	zi = 0;
	iter = 0;
	while ((zr * zr + zi * zi) < ESCAPE_RADIUS && iter < MAX_ITER)
	{
		zr2 = zr * zr;
		zi2 = zi * zi;
		if (zr2 + zi2 > ESCAPE_RADIUS)
			break ;
		zi = -2 * zr * zi + ci;
		zr = zr2 - zi2 + cr;
		iter++;
	}
	return (iter);
}

void	draw_fractal(t_data *data, int color_table[MAX_ITER])
{
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		draw_fractal_row(data, y, color_table);
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
}
