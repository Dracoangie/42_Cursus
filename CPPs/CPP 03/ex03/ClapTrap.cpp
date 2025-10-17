/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:31:55 by angnavar          #+#    #+#             */
/*   Updated: 2025/10/17 10:36:18 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): name(""), hitPoints(10),
 energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap Default Constructor called!" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: name(name), hitPoints(10), energyPoints(2), attackDamage(0)
{
    std::cout << "ClapTrap Constructor called!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
    *this = src;
	std::cout << "ClapTrap Copy Constructor called!" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Destructor called!" << std::endl;
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
		oss << this->name << " tries to attack " << target
			<< " but fail!";
	}
	else
	{
		oss << this->name << " attacks " << target
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
	oss << RED  << this->name << " takes "<< amount  << " points of damage!" << RESET << std::endl;
    if (hitPoints <= 0) 
	    oss << RED  << this->name << " dies under terrible circunstances..." << RESET << std::endl;
	
	std::cout << CYAN;
	typeWrite(oss.str());
	std::cout << RESET;
}

void ClapTrap::beRepaired(unsigned int amount)
{	
	std::ostringstream oss;

	if(energyPoints <= 0)
		oss << this->name << " tries to heal " << " but fail!";
	else
	{
		hitPoints += amount;
		oss << this->name << " heals " << amount << "! ";
		energyPoints --;
	}

	std::cout << GREEN;
	typeWrite(oss.str());
	std::cout << RESET << std::endl;
}

const std::string ClapTrap::cat1[] = {
    "                         ,         ",
    "                       _/((        ",
    "              _.---. .'   `\\      ",
    "            .'      `     ^ T=     ",
    "           /     \\       .--'     ",
    "          |      /       )'-.      ",
    "          ; ,   <__..-(   '-.)     ",
    "          \\ \\-.__)    ``--._)    ",
    "           '.'-.__.-.              ",
    "             ''-...-'              "
};

const std::string ClapTrap::cat4[] = {
    "                             ,     ",
    "                           _/((    ",
    "                  _.---. .'   `\\  ",
    "                .'      `     ^ T= ",
    "               /     \\       .--' ",
    "              |      /       )'-.  ",
    "              ; ,   <__..-(   '-.) ",
    "              \\ \\-.__)    ``--._)",
    "               '.'-.__.-.          ",
    "                 ''-...-'          "
};

const std::string ClapTrap::cat2[] = {
    "                  ,",
    "                 \\)\\_",
    "                /    '. .---._",
    "              =P ^     `      '.",
    "               `--.       /     \\",
    "               .-'(       \\      |",
    "              (.-'   )-..__>   , ;",
    "              (_.--``    (__.-/ /",
    "                      .-.__.-'.'",
    "                       '-...-'"
};

const std::string ClapTrap::cat3[] = {
    "             ,",
    "            \\)\\_",
    "           /    '. .---._",
    "         =P ^     `      '.",
    "          `--.       /     \\",
    "          .-'(       \\      |",
    "         (.-'   )-..__>   , ;",
    "         (_.--``    (__.-/ /",
    "                 .-.__.-'.'",
    "                  '-...-'"
};