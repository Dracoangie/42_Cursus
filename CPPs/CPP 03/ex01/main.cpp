/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:31:55 by angnavar          #+#    #+#             */
/*   Updated: 2025/10/17 10:24:25 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			std::cout << PINK << ClapTrap::cat1[i] << RESET << std::endl;
	}
	std::cout << GREEN;
	ClapTrap::typeWrite("First ScavTrap apeared!");
	std::cout << RESET;
	usleep(400000);
	for (size_t j = 0; j < lines; ++j)
	{
		usleep(80000);
		std::cout << "\033[2J\033[1;1H";
		for (size_t i = 0; i < lines - j-1; ++i)
			std::cout << PINK << ClapTrap::cat1[i] << RESET << std::endl;
		for (size_t i = 0; i < j + 1; ++i)
			std::cout << PINK << std::left << std::setw(40) << ClapTrap::cat1[(lines - j -1) + i] 
			<< std::right << ClapTrap::cat2[i] << RESET << std::endl;
	}
	std::cout << GREEN;
	ClapTrap::typeWrite("Second ScavTrap apeared!");
	std::cout << RESET;
	usleep(400000);
}

void catRest()
{
	std::cout << "\033[2J\033[1;1H";
	std::cout << std::endl;
	printCatsFacingEachOther(PINK, PINK, 0);
	usleep(200000);

	std::cout << "\033[2J\033[1;1H";
	printCatsFacingEachOther(PINK, PINK, 0);
	usleep(200000);

	std::cout << "\033[2J\033[1;1H";
	std::cout << std::endl;
	printCatsFacingEachOther(PINK, PINK, 0);
	usleep(200000);

	std::cout << "\033[2J\033[1;1H";
	printCatsFacingEachOther(PINK, PINK, 0);
	usleep(200000);
}

void catAction(ScavTrap *Simba, ScavTrap *Nala)
{
	catRest();

	std::cout << "\033[2J\033[1;1H";
	printCatsFacingEachOther(CYAN, PINK, 1);
	Simba->attack("Nala");
	usleep(800000);
	std::cout << "\033[2J\033[1;1H";
	printCatsFacingEachOther(PINK, RED, 0);
	Nala->takeDamage(20);
	usleep(800000);

	catRest();

	std::cout << "\033[2J\033[1;1H";
	printCatsFacingEachOther(PINK, CYAN, 2);
	Nala->attack("Simba");
	usleep(800000);
	std::cout << "\033[2J\033[1;1H";
	printCatsFacingEachOther(RED, PINK, 0);
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
	ClapTrap::typeWrite("They both enter on Gate Keeper mode!");
	std::cout << std::endl;
	ClapTrap::typeWrite("lets drop this here . . .", 100000);
	std::cout << RESET << std::endl;
	sleep(1);
}

int catBattle( void )
{
	std::cout << "\033[2J\033[1;1H";

	ScavTrap Simba("Simba");
	ScavTrap Nala("Nala");
	
	printCat((sizeof(ClapTrap::cat1) / sizeof(ClapTrap::cat1[0])));
	sleep(1);

	catAction(&Simba, &Nala);

	std::cout << "\033[2J\033[1;1H";
	printCatsFacingEachOther(MAGENTA, PINK, 0);
	usleep(200000);
	Simba.guardGate();
	std::cout << "\033[2J\033[1;1H";
	printCatsFacingEachOther(MAGENTA, MAGENTA, 0);
	usleep(200000);
	Nala.guardGate();

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
	ScavTrap scavTrap1("First");
	ScavTrap scavTrap2("Second");

	scavTrap1.attack("Second");
	scavTrap2.takeDamage(20);
	scavTrap2.attack("First");
	scavTrap1.takeDamage(20);

	scavTrap1.beRepaired(20);
	scavTrap2.beRepaired(20);

	scavTrap1.guardGate();
	scavTrap2.guardGate();

	return 0;
}