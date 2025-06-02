/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:31:55 by angnavar          #+#    #+#             */
/*   Updated: 2025/05/21 13:39:20 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define CYAN    "\033[36m"
#define YELLOW  "\033[33m"
#define MAGENTA "\033[35m"

bool bsp(Point const a, Point const b, Point const c, Point const point);

void test(Point const &a, Point const &b, Point const &c, Point const &p)
{
	(void)a;
	(void)b;
	(void)c;
	std::cout << CYAN << "Testing point (" << p.getX().toFloat()
	          << ", " << p.getY().toFloat() << "): " << RESET;

	if (bsp(a, b, c, p))
		std::cout << GREEN << "Inside the triangle" << RESET << std::endl;
	else
		std::cout << RED << "Outside the triangle" << RESET << std::endl;
}

int main()
{
	Point a(0.0f, 0.0f);
	Point b(5.0f, 0.0f);
	Point c(0.0f, 5.0f);

	std::cout << CYAN << "=== Triangle vertex ===" << RESET << std::endl;
	std::cout << "A(0, 0), B(5, 0), C(0, 5)\n" << std::endl;

	Point inside(2.0f, 2.0f);
	Point inside2(2.5f, 2.0f);
	Point edge(2.5f, 0.0f);
	Point vertex(0.0f, 0.0f);
	Point outside(5.0f, 5.0f);

	test(a, b, c, inside);
	test(a, b, c, inside2);
	test(a, b, c, edge);
	test(a, b, c, vertex);
	test(a, b, c, outside);

	return 0;
}