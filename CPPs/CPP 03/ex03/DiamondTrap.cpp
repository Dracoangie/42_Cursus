/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:31:55 by angnavar          #+#    #+#             */
/*   Updated: 2025/10/17 10:36:30 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	this->name = "DiamondTrap";
	ClapTrap::name = name + "_clap_name";
    FragTrap::hitPoints = 100;
    ScavTrap::energyPoints = 50;
    FragTrap::attackDamage = 20;
    std::cout << "DiamondTrap Default Constructor called!" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
{
    this->name = name;
    ClapTrap::name = name + "_clap_name";
    FragTrap::hitPoints = 100;
    ScavTrap::energyPoints = 50;
    FragTrap::attackDamage = 20;
    std::cout << "DiamondTrap Constructor called with name: " << name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src)
    : ClapTrap(src), FragTrap(src), ScavTrap(src)
{
    *this = src;
    std::cout << "DiamondTrap Copy Constructor called!" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap Destructor called!" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &cpy)
{
    if (this != &cpy)
    {
        FragTrap::operator=(cpy);
        ScavTrap::operator=(cpy);
    }
    return *this;
}

void DiamondTrap::whoAmI(void)
{
    std::ostringstream oss;
	oss << PINK << this->name << " is confused! it doesn't know its own name. " << std::endl
		<< "is the ClapTrap name: " << ClapTrap::name << std::endl
		<< "or the DiamondTrap name: " << this->name << std::endl << RESET;
	ClapTrap::typeWrite(oss.str());
}	

void DiamondTrap::attack(const std::string& target)
{
	ClapTrap::attack(target);
}

void DiamondTrap::guardGate(void)
{
	ScavTrap::guardGate();
}

void DiamondTrap::highFivesGuys(void)
{
	FragTrap::highFivesGuys();
}

void DiamondTrap::takeDamage(unsigned int amount)
{
	ClapTrap::takeDamage(amount);
}

void DiamondTrap::beRepaired(unsigned int amount)
{
	ClapTrap::beRepaired(amount);
}