/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:30:20 by angnavar          #+#    #+#             */
/*   Updated: 2025/02/03 16:14:46 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

void	set_data(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Fract-ol");
	data->img.img_ptr = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img.img_pixels_ptr = mlx_get_data_addr(data->img.img_ptr,
			&data->img.bits_per_pixel, &data->img.line_len, &data->img.endian);
	data->zoom = 0.8;
	data->move_x = -0.5;
	data->move_y = 0;
	data->julia_re = -0.7;
	data->julia_im = 0.27015;
	if (data->color == 3)
		generate_color_table_rd(MAX_ITER, data->color_table);
	else
		generate_color_table(MAX_ITER, data->color_table, data->color);
	data->julia_im = 0.27015;
}

void	check_fractol_name(t_data *data, char *argv)
{
	if (ft_strcmp(argv, "mandelbrot") == 0)
		data->fractal = 1;
	else if (ft_strcmp(argv, "julia") == 0)
		data->fractal = 0;
	else if (ft_strcmp(argv, "burning_ship") == 0)
		data->fractal = 2;
	else if (ft_strcmp(argv, "tricorn") == 0)
		data->fractal = 3;
	else
	{
		printf("valid fractals: [mandelbrot/julia/burning_ship]\n");
		exit(0);
	}
}

void	check_color(t_data *data, char *argv)
{
	if (!argv)
		data->color = 0;
	else if (ft_strcmp(argv, "r") == 0)
		data->color = 0;
	else if (ft_strcmp(argv, "g") == 0)
		data->color = 1;
	else if (ft_strcmp(argv, "b") == 0)
		data->color = 2;
	else if (ft_strcmp(argv, "a") == 0)
		data->color = 3;
	else
	{
		printf("valid colors: [r/g/b/a]\n");
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2 && argc != 3)
	{
		printf("valid arguments: ./fractol [m/j/b/t] [r/g/b/a]\n");
		return (1);
	}
	check_fractol_name(&data, argv[1]);
	check_color(&data, argv[2]);
	set_data(&data);
	draw_fractal(&data, data.color_table);
	mlx_mouse_hook(data.win, mouse_hook, &data);
	mlx_key_hook(data.win, handle_input, &data);
	mlx_hook(data.win, DestroyNotify, NoEventMask, (void *)exit_program, &data);
	mlx_loop(data.mlx);
	return (0);
}
