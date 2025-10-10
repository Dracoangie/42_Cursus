/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:31:55 by angnavar          #+#    #+#             */
/*   Updated: 2025/10/10 14:00:06 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	this->name = "DiamondTrap";
	ScavTrap::name = name + "_clap_name";
    FragTrap::hitPoints = 100;
    ScavTrap::ScavTrap::energyPoints = 50;
    FragTrap::FragTrap::attackDamage = 20;
    std::cout << "DiamondTrap Default Constructor called!" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
{
    this->name = name;
    FragTrap::name = name + "_clap_name";
    ScavTrap::name = name + "_clap_name";
    FragTrap::hitPoints = 100;
    ScavTrap::ScavTrap::energyPoints = 50;
    FragTrap::FragTrap::attackDamage = 20;
    std::cout << "DiamondTrap Constructor called with name: " << name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src)
    : FragTrap(src), ScavTrap(src)
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
	oss << "DiamondTrap name: " << this->name << ", ClapTrap name: " << FragTrap::name << std::endl;
	ClapTrap::typeWrite(oss.str());
}	

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::guardGate(void)
{
	ScavTrap::guardGate();
}

void DiamondTrap::highFivesGuys(void)
{
	FragTrap::highFivesGuys();
}