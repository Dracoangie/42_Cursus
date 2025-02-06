/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:56:31 by angnavar          #+#    #+#             */
/*   Updated: 2025/02/02 23:12:24 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "../includes/libft/libft.h"
# include "../includes/minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <stdint.h>
# define ESCAPE_RADIUS 4.0

# define SIDE_LEN 800
# define WIDTH 500
# define HEIGHT 500

# define MAX_ITER 254
# define ESC_RAD 4

/* Structs */
typedef struct s_img
{
	void	*img_ptr;
	char	*img_pixels_ptr;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
}			t_img;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		fractal;
	float	zoom;
	float	move_x;
	float	move_y;
	t_img	img;
	float	julia_re;
	float	julia_im;
	float	max_iter;
	int		color;
	int		color_table[MAX_ITER];
}			t_data;

/* Helper */
float		abs_float(float x);
int			ft_strcmp(const char *s1, const char *s2);
void		put_pixel(t_data *data, int x, int y, int color);
int			set_color(int iter, int color_table[MAX_ITER]);
void		draw_fractal_row(t_data *data, int y, int color_table[MAX_ITER]);

/* Input */
int			handle_input(int keysym, t_data *data);
int			mouse_hook(int button, int x, int y, t_data *data);
void		exit_program(t_data *data);

/* Fractals */
int			julia(float cr, float ci);
int			mandelbrot(float zr, float zi, float cr, float ci);
int			burning_ship(float cr, float ci);
int			tricorn(float cr, float ci);
void		draw_fractal(t_data *data, int color_table[MAX_ITER]);

/* Colors */
void		generate_color_table(int iter, int color_table[iter],
				int colortype);
void		generate_color_table_rd(int iter, int color_table[iter]);

#endif