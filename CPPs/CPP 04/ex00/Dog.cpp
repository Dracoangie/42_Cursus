/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:39:15 by angnavar          #+#    #+#             */
/*   Updated: 2025/10/13 17:12:35 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	std::cout << GREEN << "Dog default constructor called" << RESET << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << YELLOW << "Dog copy constructor called" << RESET << std::endl;
	*this = other;
}

Dog::~Dog()
{
	std::cout << RED << "Dog destructor called" << RESET << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << CYAN << "Dog assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout << MAGENTA << "Wooooooof!!" << RESET << std::endl;
}