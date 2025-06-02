/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:31:48 by angnavar          #+#    #+#             */
/*   Updated: 2025/05/21 14:27:05 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0)
{
}

Point::Point(const Point &src) : x(src.x), y(src.y)
{
}

Point::Point(const float x_val, const float y_val) : x(x_val), y(y_val) 
{
}

Point::~Point()
{
}

Fixed Point::getX() const
{
    return (this->x);
}

Fixed Point::getY() const
{
    return (this->y);
}

Point &Point::operator=(const Point &cpy)
{
	this->x = cpy.x;
	this->y = cpy.y;
	return (*this);
}
