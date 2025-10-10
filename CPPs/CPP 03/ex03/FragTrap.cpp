/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:31:55 by angnavar          #+#    #+#             */
/*   Updated: 2025/10/10 13:52:36 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
    : ClapTrap("FragTrap")
{
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    std::cout << "FragTrap Default Constructor called!" << std::endl;
}

FragTrap::FragTrap(std::string name)
    : ClapTrap(name)
{
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    std::cout << "FragTrap Constructor called with name: " << name << std::endl;
}

FragTrap::FragTrap(const FragTrap &src)
    : ClapTrap(src)
{
    *this = src;
    std::cout << "FragTrap Copy Constructor called!" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor called!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &cpy)
{
    if (this != &cpy)
    {
        ClapTrap::operator=(cpy);
    }
    return *this;
}

void FragTrap::attack(const std::string& target)
{
    std::ostringstream oss;
    if (energyPoints <= 0)
    {
        oss << "FragTrap " << name << " tries to attack " << target
            << " but fails!";
    }
    else
    {
        oss << "FragTrap " << name << " attacks " << target
            << " causing " << attackDamage << " points of damage!";
        energyPoints--;
    }

    std::cout << CYAN;
    typeWrite(oss.str());
    std::cout << RESET << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::ostringstream oss;

    oss << YELLOW << "FragTrap " << name << " is giving a high five!"
	<< std::endl << " (●ゝω)ノヽ(∀＜●)" << RESET << std::endl;
    typeWrite(oss.str());
}