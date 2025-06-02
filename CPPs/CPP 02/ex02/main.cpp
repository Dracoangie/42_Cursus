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

#include "Fixed.hpp"

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define CYAN    "\033[36m"
#define YELLOW  "\033[33m"
#define MAGENTA "\033[35m"


int main(void)
{
	std::cout << MAGENTA << "=== Constructores ===" << RESET << std::endl;
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;

	std::cout << CYAN << "\n=== Incrementos ===" << RESET << std::endl;
	std::cout << "++a: " << ++a << std::endl;
	std::cout << "a después de ++a: " << a << std::endl;
	std::cout << "a++: " << a++ << std::endl;
	std::cout << "a después de a++: " << a << std::endl;

	std::cout << YELLOW << "\n=== Aritmética ===" << RESET << std::endl;
	Fixed c(10);
	Fixed d(3);
	std::cout << "c: " << c << ", d: " << d << std::endl;
	std::cout << "c + d: " << (c + d) << std::endl;
	std::cout << "c - d: " << (c - d) << std::endl;
	std::cout << "c * d: " << (c * d) << std::endl;
	std::cout << "c / d: " << (c / d) << std::endl;

	std::cout << GREEN << "\n=== Comparaciones ===" << RESET << std::endl;
	std::cout << "c > d: " << (c > d) << std::endl;
	std::cout << "c < d: " << (c < d) << std::endl;
	std::cout << "c >= d: " << (c >= d) << std::endl;
	std::cout << "c <= d: " << (c <= d) << std::endl;
	std::cout << "c == d: " << (c == d) << std::endl;
	std::cout << "c != d: " << (c != d) << std::endl;

	std::cout << RED << "\n=== min / max ===" << RESET << std::endl;
	std::cout << "min(c, d): " << Fixed::min(c, d) << std::endl;
	std::cout << "max(c, d): " << Fixed::max(c, d) << std::endl;
	std::cout << "min(a, b): " << Fixed::min(a, b) << std::endl;
	std::cout << "max(a, b): " << Fixed::max(a, b) << std::endl;

	return 0;
}