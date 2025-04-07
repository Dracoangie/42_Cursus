/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:32:19 by angnavar          #+#    #+#             */
/*   Updated: 2025/02/10 18:23:31 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

int	julia(double cr, double ci, t_data *data)
{
	float	zr;
	float	zi;
	int		iter;
	float	zr2;
	float	zi2;

	zr = 0;
	zi = 0;
	iter = 0;
	while ((zr * zr + zi * zi) < ESCAPE_RADIUS && iter < data->max_iter)
	{
		zr2 = zr * zr;
		zi2 = zi * zi;
		if (zr2 + zi2 > ESCAPE_RADIUS)
			break ;
		zi = 2 * zr * zi + ci;
		zr = zr2 - zi2 + cr;
		iter++;
	}
	return (iter);
}

int	mandelbrot(double zr, double zi, t_data *data)
{
	int		iter;
	float	zr2;
	float	zi2;

	iter = 0;
	while ((zr * zr + zi * zi) < ESCAPE_RADIUS && iter < data->max_iter)
	{
		zr2 = zr * zr;
		zi2 = zi * zi;
		if (zr2 + zi2 > ESCAPE_RADIUS)
			break ;
		zi = 2 * zr * zi + data->julia_im;
		zr = zr2 - zi2 + data->julia_re;
		iter++;
	}
	return (iter);
}

int	burning_ship(double cr, double ci, t_data *data)
{
	float	zr;
	float	zi;
	int		iter;
	float	zr2;
	float	zi2;

	zr = 0;
	zi = 0;
	iter = 0;
	while ((zr * zr + zi * zi) < ESCAPE_RADIUS && iter < data->max_iter)
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

int	tricorn(double cr, double ci, t_data *data)
{
	float	zr;
	float	zi;
	int		iter;
	float	zr2;
	float	zi2;

	zr = 0;
	zi = 0;
	iter = 0;
	while ((zr * zr + zi * zi) < ESCAPE_RADIUS && iter < data->max_iter)
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

void	draw_fractal(t_data *data, int *color_table)
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
