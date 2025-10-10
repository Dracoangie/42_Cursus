/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:31:55 by angnavar          #+#    #+#             */
/*   Updated: 2025/10/10 13:10:09 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
    : ClapTrap("ScavTrap")
{
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap Default Constructor called!" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
    : ClapTrap(name)
{
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap Constructor called with name: " << name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src)
    : ClapTrap(src)
{
    *this = src;
    std::cout << "ScavTrap Copy Constructor called!" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor called!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &cpy)
{
    if (this != &cpy)
    {
        ClapTrap::operator=(cpy);
    }
    return *this;
}

void ScavTrap::attack(const std::string& target)
{
    std::ostringstream oss;
    if (energyPoints <= 0)
    {
        oss << "ScavTrap " << name << " tries to attack " << target
            << " but fails!";
    }
    else
    {
        oss << "ScavTrap " << name << " attacks " << target
            << " causing " << attackDamage << " points of damage!";
        energyPoints--;
    }

    std::cout << CYAN;
    typeWrite(oss.str());
    std::cout << RESET << std::endl;
}

void ScavTrap::guardGate()
{
    std::ostringstream oss;

    oss << MAGENTA << "ScavTrap " << name << " is now in Gate Keeper mode!" << RESET << std::endl;
    typeWrite(oss.str());
}