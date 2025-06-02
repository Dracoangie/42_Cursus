/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:31:55 by angnavar          #+#    #+#             */
/*   Updated: 2025/05/20 13:54:10 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): name(""), hitPoints(10),
 energyPoints(10), attackDamage(0)
{
}

ClapTrap::ClapTrap(std::string name)
	: name(name), hitPoints(10), energyPoints(10), attackDamage(0)
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

void ClapTrap::typeWrite(const std::string& text, int delayMicroseconds = 30000)
{
	for (size_t i = 0; i < text.length(); ++i) {
		std::cout << text[i] << std::flush;
		usleep(delayMicroseconds);
	}
}

void ClapTrap::attack(const std::string &target)
{	
    std::cout << CYAN;
    typeWrite("ClapTrap ");
    typeWrite(name);
    typeWrite(" causing ");
	std::cout << attackDamage ;
    typeWrite(" points of damage!");
    std::cout << RESET;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (amount > static_cast<unsigned int>(hitPoints))
        hitPoints = 0;
    else hitPoints -= amount;
	std::cout << RED  << name << " takes "<< amount  << " points of damage!" << RESET << std::endl;
    if (hitPoints < 0) 
	    std::cout << RED  << name << " dies under terrible circunstances..." << RESET << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{	
    hitPoints += amount;
	std::cout << GREEN << "ClapTrap "  << name << " heals " << amount << "! " << RESET << std::endl;
}