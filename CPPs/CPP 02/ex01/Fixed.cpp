/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:33:11 by angnavar          #+#    #+#             */
/*   Updated: 2025/05/21 14:28:07 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(const int int_num)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = int_num << fixed_bits;
}

Fixed::Fixed(const float float_num)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = float_num * (1 << fixed_bits);
}

Fixed &Fixed::operator=(const Fixed &cpy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->value = cpy.getRawBits();
	return (*this);
}

std::ostream &operator<<(std::ostream &ostream, Fixed const &fixed)
{
	ostream << fixed.toFloat();
	return (ostream);
}

int Fixed::getRawBits(void) const
{
	return (this->value);
}

void Fixed::setRawBits(const int raw)
{
	this->value = raw;
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(value) / (1 << fixed_bits));
}

int Fixed::toInt(void) const
{
	return (value >> fixed_bits);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}