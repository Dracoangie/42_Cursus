/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:45:43 by angnavar          #+#    #+#             */
/*   Updated: 2025/01/31 17:19:19 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

int	handle_input(int keysym, t_data *data)
{
	float	move_step;

	move_step = 0.1 / data->zoom;
	if (keysym == XK_Escape)
		exit_program(data);
	else if (keysym == XK_w || keysym == XK_Up)
		data->move_y -= move_step;
	else if (keysym == XK_s || keysym == XK_Down)
		data->move_y += move_step;
	else if (keysym == XK_a || keysym == XK_Left)
		data->move_x -= move_step;
	else if (keysym == XK_d || keysym == XK_Right)
		data->move_x += move_step;
	draw_fractal(data, data->color_table);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_data *data)
{
	float	zoom_factor;
	float	mouse_x;
	float	mouse_y;

	zoom_factor = 1;
	mouse_x = (x - WIDTH / 2.0) / (0.5 * data->zoom * WIDTH) + data->move_x;
	mouse_y = (y - HEIGHT / 2.0) / (0.5 * data->zoom * HEIGHT) + data->move_y;
	if (button == 4)
	{
		zoom_factor = 1.1;
		mouse_x = -((x - WIDTH / 2.0) / (0.5 * data->zoom * WIDTH))
			+ data->move_x;
		mouse_y = -((y - HEIGHT / 2.0) / (0.5 * data->zoom * HEIGHT))
			+ data->move_y;
	}
	else if (button == 5)
		zoom_factor = 0.9;
	else
		return (0);
	data->zoom *= zoom_factor;
	data->move_x = mouse_x + (data->move_x - mouse_x) * zoom_factor;
	data->move_y = mouse_y + (data->move_y - mouse_y) * zoom_factor;
	draw_fractal(data, data->color_table);
	return (0);
}

void	exit_program(t_data *data)
{
	if (data->img.img_ptr)
		mlx_destroy_image(data->mlx, data->img.img_ptr);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	exit(0);
}
