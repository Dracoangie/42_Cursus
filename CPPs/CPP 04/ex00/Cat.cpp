/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:39:15 by angnavar          #+#    #+#             */
/*   Updated: 2025/10/13 17:12:52 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	std::cout << GREEN << "Cat default constructor called" << RESET << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << YELLOW << "Cat copy constructor called" << RESET << std::endl;
	*this = other;
}

Cat::~Cat()
{
	std::cout << RED << "Cat destructor called" << RESET << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << CYAN << "Cat assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << MAGENTA << "Meow Meow?" << RESET << std::endl;
}