/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:39:15 by angnavar          #+#    #+#             */
/*   Updated: 2025/10/13 17:43:01 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->type = "WrongCat";
	std::cout << GREEN << "WrongCat default constructor called" << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	std::cout << YELLOW << "WrongCat copy constructor called" << RESET << std::endl;
	*this = other;
}

WrongCat::~WrongCat()
{
	std::cout << RED << "WrongCat destructor called" << RESET << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	std::cout << CYAN << "WrongCat assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		WrongAnimal::operator=(other);
	}
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << BMAGENTA << "Meow Meow? But with a dog bark! For example" << RESET << std::endl;
}