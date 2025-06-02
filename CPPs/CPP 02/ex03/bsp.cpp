/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:31:48 by angnavar          #+#    #+#             */
/*   Updated: 2025/05/21 14:27:05 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const p)
{
	float ab_x = b.getX().toFloat() - a.getX().toFloat();
	float ab_y = b.getY().toFloat() - a.getY().toFloat();

	float ac_x = c.getX().toFloat() - a.getX().toFloat();
	float ac_y = c.getY().toFloat() - a.getY().toFloat();

	float ap_x = p.getX().toFloat() - a.getX().toFloat();
	float ap_y = p.getY().toFloat() - a.getY().toFloat();

	float denominator = ab_x * ac_y - ab_y * ac_x;
	if (denominator == 0)
		return false;

	float w1 = (ap_x * ac_y - ap_y * ac_x) / denominator;
	float w2 = (ab_x * ap_y - ab_y * ap_x) / denominator;

	return (w1 > 0.0f && w2 > 0.0f && (w1 + w2) < 1.0f);
}
