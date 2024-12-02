/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:56:31 by angnavar          #+#    #+#             */
/*   Updated: 2024/11/21 14:00:34 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL

# define WIN_WIDTH			400
# define WIN_HEIGHT			400

typedef struct	s_data {
	// structura que tiene todas las variables importantes del programa, display scree visual loop, etc
	void	*mlx;
	void	*win;
}				t_data;

#endif