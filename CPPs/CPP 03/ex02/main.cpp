/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:31:55 by angnavar          #+#    #+#             */
/*   Updated: 2025/10/17 10:25:44 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
# include <iomanip>

void printCatsFacingEachOther (std::string color1, std::string color2, int attack)
{
	for (size_t i = 0; i < (sizeof(ClapTrap::cat1) / sizeof(ClapTrap::cat1[0])); ++i) {
		std::cout << color1 << std::left  << std::setw(40) << ((attack == 1) ? ClapTrap::cat4[i]: ClapTrap::cat1[i]) << std::setw(5) << RESET 
				<< color2 << std::right << ((attack == 2) ? ClapTrap::cat3[i]: ClapTrap::cat2[i]) << RESET << std::endl;
	}
}

void printCat(size_t lines)
{	
	for (size_t j = 0; j < lines; ++j)
	{
		usleep(80000);
		std::cout << "\033[2J\033[1;1H";
		for (size_t i = 0; i < lines - j -1; ++i)
			std::cout << std::endl;
		for (size_t i = 0; i < j + 1; ++i)
			std::cout << BGREEN << ClapTrap::cat1[i] << RESET << std::endl;
	}
	std::cout << GREEN;
	ClapTrap::typeWrite("First FragTrap apeared!");
	std::cout << RESET;
	usleep(400000);
	for (size_t j = 0; j < lines; ++j)
	{
		usleep(80000);
		std::cout << "\033[2J\033[1;1H";
		for (size_t i = 0; i < lines - j-1; ++i)
			std::cout << BGREEN << ClapTrap::cat1[i] << RESET << std::endl;
		for (size_t i = 0; i < j + 1; ++i)
			std::cout << BGREEN << std::left << std::setw(40) << ClapTrap::cat1[(lines - j -1) + i] 
			<< std::right << ClapTrap::cat2[i] << RESET << std::endl;
	}
	std::cout << GREEN;
	ClapTrap::typeWrite("Second FragTrap apeared!");
	std::cout << RESET;
	usleep(400000);
}

void catRest()
{
	std::cout << "\033[2J\033[1;1H";
	std::cout << std::endl;
	printCatsFacingEachOther(BGREEN, BGREEN, 0);
	usleep(200000);

	std::cout << "\033[2J\033[1;1H";
	printCatsFacingEachOther(BGREEN, BGREEN, 0);
	usleep(200000);

	std::cout << "\033[2J\033[1;1H";
	std::cout << std::endl;
	printCatsFacingEachOther(BGREEN, BGREEN, 0);
	usleep(200000);

	std::cout << "\033[2J\033[1;1H";
	printCatsFacingEachOther(BGREEN, BGREEN, 0);
	usleep(200000);
}

void catAction(FragTrap *Simba, FragTrap *Nala)
{
	catRest();

	std::cout << "\033[2J\033[1;1H";
	printCatsFacingEachOther(CYAN, BGREEN, 1);
	Simba->attack("Nala");
	usleep(800000);
	std::cout << "\033[2J\033[1;1H";
	printCatsFacingEachOther(BGREEN, RED, 0);
	Nala->takeDamage(30);
	usleep(800000);

	catRest();

	std::cout << "\033[2J\033[1;1H";
	printCatsFacingEachOther(BGREEN, CYAN, 2);
	Nala->attack("Simba");
	usleep(800000);
	std::cout << "\033[2J\033[1;1H";
	printCatsFacingEachOther(RED, BGREEN, 0);
	Simba->takeDamage(30);
	usleep(800000);
	
	catRest();
}

void endBattle()
{
	sleep(1);
	std::cout << CYAN;
	ClapTrap::typeWrite(".  .  .", 400000);
	std::cout << std::endl;
	ClapTrap::typeWrite("They are friends now!");
	std::cout << std::endl;
	ClapTrap::typeWrite("The battle is over now . . . ", 100000);
	ClapTrap::typeWrite("Or did you expect friends to keep fighting?", 20000);
	std::cout << RESET << std::endl;
	sleep(1);
}

int catBattle( void )
{
	std::cout << "\033[2J\033[1;1H";

	FragTrap Simba("Simba");
	FragTrap Nala("Nala");
	
	printCat((sizeof(ClapTrap::cat1) / sizeof(ClapTrap::cat1[0])));
	sleep(1);

	catAction(&Simba, &Nala);

	std::cout << "\033[2J\033[1;1H";
	printCatsFacingEachOther(YELLOW, BGREEN, 0);
	usleep(200000);
	Simba.highFivesGuys();
	std::cout << "\033[2J\033[1;1H";
	printCatsFacingEachOther(YELLOW, YELLOW, 0);
	usleep(200000);
	Nala.highFivesGuys();

	endBattle();
	return 0;
}

int main( int argc, char** argv )
{
	(void) argc;

	if(argv[1])
	{
		std::string mode = argv[1];
		if(mode == "cat")
		{
			catBattle();
			return 0;
		}
	}
	FragTrap FragTrap1("First");
	FragTrap FragTrap2("Second");

	FragTrap1.attack("Second");
	FragTrap2.takeDamage(30);
	FragTrap2.attack("First");
	FragTrap1.takeDamage(30);

	FragTrap1.beRepaired(30);
	FragTrap2.beRepaired(30);

	FragTrap1.highFivesGuys();
	FragTrap2.highFivesGuys();

	return 0;
}