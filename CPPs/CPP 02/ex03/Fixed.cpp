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

// ===================  constructors  ===================

Fixed::Fixed()
{
	this->value = 0;
}

Fixed::Fixed(const Fixed &src)
{
	*this = src;
}

Fixed::Fixed(const int int_num)
{
	this->value = int_num << fixed_bits;
}

Fixed::Fixed(const float float_num)
{
	this->value = static_cast<int>(roundf(float_num * (1 << fixed_bits)));
}

// ===================  past operators  ===================

Fixed &Fixed::operator=(const Fixed &cpy)
{
	this->value = cpy.getRawBits();
	return (*this);
}

std::ostream &operator<<(std::ostream &ostream, Fixed const &fixed)
{
	ostream << fixed.toFloat();
	return (ostream);
}

// ===================  comparison operators  ===================

bool Fixed::operator>(Fixed const &other) const
{
    return (this->value > other.value);
}

bool Fixed::operator<(Fixed const &other) const
{
    return (this->value < other.value);
}

bool Fixed::operator>=(Fixed const &other) const
{
    return (this->value >= other.value);
}

bool Fixed::operator<=(Fixed const &other) const
{
    return (this->value <= other.value);
}

bool Fixed::operator==(Fixed const &other) const
{
    return (this->value == other.value);
}

bool Fixed::operator!=(Fixed const &other) const
{
    return (this->value != other.value);
}

// ===================  arithmetic operators  ===================

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed result;
	result.value = this->value + other.value;
	return (result);
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed result;
	result.value = this->value - other.value;
	return (result);
}

Fixed Fixed::operator*(const Fixed &other) const
{
   	Fixed result;
	result.value = (this->value * other.value) >> fixed_bits;
	return (result);
}

Fixed Fixed::operator/(const Fixed &other) const
{
   	Fixed result;
	result.value = (this->value << fixed_bits) / other.value;
	return (result);
}

// ===================  in/decrements  ===================

Fixed& Fixed::operator++()
{
	++this->value;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	this->value++;
	return (temp);
}

Fixed& Fixed::operator--()
{
	--this->value;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	this->value--;
	return (temp);
}

// ===================  min max  ===================

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b) ? a : b;
}

// ===================  Fixed Functions  ===================
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
	return static_cast<int>(roundf(this->toFloat()));
}

Fixed::~Fixed()
{
}