/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 18:10:02 by angnavar          #+#    #+#             */
/*   Updated: 2025/10/13 19:09:00 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << PINK << "Brain default constructor called" << RESET << std::endl;
	for (int i = 0; i < 100; i++)
	{
		std::ostringstream oss;
		oss << "Idea " << i + 1;
		this->ideas[i] = oss.str();
	}
}

Brain::Brain(const Brain &other)
{
	std::cout << PINK << "Brain copy constructor called" << RESET << std::endl;
	*this = other;
}

Brain::~Brain()
{
	std::cout << PINK << "Brain destructor called" << RESET << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
	std::cout << PINK << "Brain assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
		{
			this->ideas[i] = other.ideas[i];
		}
	}
	return *this;
}