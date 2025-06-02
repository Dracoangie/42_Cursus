/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:31:48 by angnavar          #+#    #+#             */
/*   Updated: 2025/05/21 14:27:05 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP

# define POINT_HPP

#include "Fixed.hpp"

class Point
{
	Fixed	x;
	Fixed	y;

public:
	Point();
	Point(const Point &src);
	Point(const float x_val, const float y_val);
	~Point();

	Fixed getX() const;
	Fixed getY() const;

	Point&	operator=(const Point &cpy);
};

#endif