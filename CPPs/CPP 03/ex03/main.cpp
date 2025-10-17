/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:31:55 by angnavar          #+#    #+#             */
/*   Updated: 2025/10/17 10:28:06 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iomanip>

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
			std::cout << BLUE << ClapTrap::cat1[i] << RESET << std::endl;
	}
	std::cout << GREEN;
	ClapTrap::typeWrite("First DiamondTrap appeared!");
	std::cout << RESET;
	usleep(400000);
	for (size_t j = 0; j < lines; ++j)
	{
		usleep(80000);
		std::cout << "\033[2J\033[1;1H";
		for (size_t i = 0; i < lines - j-1; ++i)
			std::cout << BLUE << ClapTrap::cat1[i] << RESET << std::endl;
		for (size_t i = 0; i < j + 1; ++i)
			std::cout << BLUE << std::left << std::setw(40) << ClapTrap::cat1[(lines - j -1) + i] 
			<< std::right << ClapTrap::cat2[i] << RESET << std::endl;
	}
	std::cout << GREEN;
	ClapTrap::typeWrite("Second DiamondTrap appeared!");
	std::cout << RESET;
	usleep(400000);
}

void catRest()
{
	std::cout << "\033[2J\033[1;1H";
	std::cout << std::endl;
	printCatsFacingEachOther(BLUE, BLUE, 0);
	usleep(200000);

	std::cout << "\033[2J\033[1;1H";
	printCatsFacingEachOther(BLUE, BLUE, 0);
	usleep(200000);

	std::cout << "\033[2J\033[1;1H";
	std::cout << std::endl;
	printCatsFacingEachOther(BLUE, BLUE, 0);
	usleep(200000);

	std::cout << "\033[2J\033[1;1H";
	printCatsFacingEachOther(BLUE, BLUE, 0);
	usleep(200000);
}

void catAction(DiamondTrap *Simba, DiamondTrap *Nala)
{
	catRest();

	std::cout << "\033[2J\033[1;1H";
	printCatsFacingEachOther(CYAN, BLUE, 1);
	Simba->attack("Nala");
	usleep(800000);
	std::cout << "\033[2J\033[1;1H";
	printCatsFacingEachOther(BLUE, RED, 0);
	Nala->takeDamage(20);
	usleep(800000);

	catRest();

	std::cout << "\033[2J\033[1;1H";
	printCatsFacingEachOther(BLUE, CYAN, 2);
	Nala->attack("Simba");
	usleep(800000);
	std::cout << "\033[2J\033[1;1H";
	printCatsFacingEachOther(RED, BLUE, 0);
	Simba->takeDamage(20);
	usleep(800000);
	
	catRest();
}

void endBattle()
{
	sleep(1);
	std::cout << CYAN;
	ClapTrap::typeWrite(".  .  .", 400000);
	std::cout << std::endl;
	ClapTrap::typeWrite("Both are confused!");
	std::cout << std::endl;
	ClapTrap::typeWrite("They cant fight anymore . . . ", 100000);
	std::cout << RESET << std::endl;
	sleep(1);
}

int catBattle( void )
{
	std::cout << "\033[2J\033[1;1H";

	DiamondTrap Simba("Simba");
	DiamondTrap Nala("Nala");
	
	printCat((sizeof(ClapTrap::cat1) / sizeof(ClapTrap::cat1[0])));
	sleep(1);

	catAction(&Simba, &Nala);

	std::cout << "\033[2J\033[1;1H";
	printCatsFacingEachOther(MAGENTA, BLUE, 0);
	usleep(200000);
	Simba.guardGate();
	std::cout << "\033[2J\033[1;1H";
	printCatsFacingEachOther(MAGENTA, MAGENTA, 0);
	usleep(200000);
	Nala.guardGate();

	std::cout << "\033[2J\033[1;1H";
	printCatsFacingEachOther(YELLOW, BLUE, 0);
	usleep(200000);
	Simba.highFivesGuys();
	std::cout << "\033[2J\033[1;1H";
	printCatsFacingEachOther(YELLOW, YELLOW, 0);
	usleep(200000);
	Nala.highFivesGuys();

	std::cout << "\033[2J\033[1;1H";
	printCatsFacingEachOther(CYAN, CYAN, 0);
	Simba.whoAmI();
	Nala.whoAmI();

	endBattle();
	return 0;
}

int main( int argc, char** argv )
{
	if (argc > 1) {
		std::string mode = argv[1];
		if (mode == "cat") {
			catBattle();
			return 0;
		}
	}

	DiamondTrap d1("First");
	DiamondTrap d2("Second");

	d1.attack("Second");
	d2.takeDamage(20);
	d2.attack("First");
	d1.takeDamage(20);

	d1.beRepaired(20);
	d2.beRepaired(20);

	d1.highFivesGuys();
	d2.highFivesGuys();

	d1.whoAmI();
	d2.whoAmI();

	return 0;
}
