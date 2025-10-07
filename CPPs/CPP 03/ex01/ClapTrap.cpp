/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:31:55 by angnavar          #+#    #+#             */
/*   Updated: 2025/10/07 23:53:32 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): name(""), hitPoints(10),
 energyPoints(10), attackDamage(0)
{
}

ClapTrap::ClapTrap(std::string name)
	: name(name), hitPoints(10), energyPoints(2), attackDamage(0)
{
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
    *this = src;
}

ClapTrap::~ClapTrap()
{
}

ClapTrap &ClapTrap::operator=(ClapTrap const & cpy)
{
	if (this != &cpy) {
		this->name = cpy.name;
		this->hitPoints = cpy.hitPoints;
		this->energyPoints = cpy.energyPoints;
		this->attackDamage = cpy.attackDamage;
	}
	return *this;
}

void ClapTrap::typeWrite(const std::string& text, int delayMicroseconds)
{
	for (size_t i = 0; i < text.length(); ++i) {
		std::cout << text[i] << std::flush;
		usleep(delayMicroseconds);
	}
}

void ClapTrap::attack(const std::string &target)
{
	std::ostringstream oss;

	if(energyPoints <= 0)
	{
		oss << "ClapTrap " << name << " tries to attack " << target
			<< " but fail!";
	}
	else
	{
		oss << "ClapTrap " << name << " attacks " << target
			<< " causing " << attackDamage << " points of damage!";
		energyPoints --;
	}
	
	std::cout << CYAN;
	typeWrite(oss.str());
	std::cout << RESET << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::ostringstream oss;

    if (amount > static_cast<unsigned int>(hitPoints))
        hitPoints = 0;
    else hitPoints -= amount;
	oss << RED  << name << " takes "<< amount  << " points of damage!" << RESET << std::endl;
    if (hitPoints <= 0) 
	    oss << RED  << name << " dies under terrible circunstances..." << RESET << std::endl;
	
	std::cout << CYAN;
	typeWrite(oss.str());
	std::cout << RESET;
}

void ClapTrap::beRepaired(unsigned int amount)
{	
	std::ostringstream oss;

	if(energyPoints <= 0)
		oss << "ClapTrap " << name << " tries to heal " << " but fail!";
	else
	{
		hitPoints += amount;
			oss<< "ClapTrap "  << name << " heals " << amount << "! ";
		energyPoints --;
	}

	std::cout << GREEN;
	typeWrite(oss.str());
	std::cout << RESET << std::endl;
}