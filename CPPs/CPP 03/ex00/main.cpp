/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:31:55 by angnavar          #+#    #+#             */
/*   Updated: 2025/10/17 10:22:28 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"
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
			std::cout << YELLOW << ClapTrap::cat1[i] << RESET << std::endl;
	}
	std::cout << GREEN;
	ClapTrap::typeWrite("First ClapTrap apeared!");
	std::cout << RESET;
	usleep(500000);
	for (size_t j = 0; j < lines; ++j)
	{
		usleep(80000);
		std::cout << "\033[2J\033[1;1H";
		for (size_t i = 0; i < lines - j-1; ++i)
			std::cout << YELLOW << ClapTrap::cat1[i] << RESET << std::endl;
		for (size_t i = 0; i < j + 1; ++i)
			std::cout << YELLOW << std::left << std::setw(40) << ClapTrap::cat1[(lines - j -1) + i] 
			<< std::right << ClapTrap::cat2[i] << RESET << std::endl;
	}
	std::cout << GREEN;
	ClapTrap::typeWrite("Second ClapTrap apeared!");
	std::cout << RESET;
	usleep(500000);
}

void catRest()
{
	std::cout << "\033[2J\033[1;1H";
	std::cout << std::endl;
	printCatsFacingEachOther(YELLOW, YELLOW, 0);
	usleep(300000);

	std::cout << "\033[2J\033[1;1H";
	printCatsFacingEachOther(YELLOW, YELLOW, 0);
	usleep(300000);

	std::cout << "\033[2J\033[1;1H";
	std::cout << std::endl;
	printCatsFacingEachOther(YELLOW, YELLOW, 0);
	usleep(300000);

	std::cout << "\033[2J\033[1;1H";
	printCatsFacingEachOther(YELLOW, YELLOW, 0);
	usleep(300000);
}

void catAction(ClapTrap Simba, ClapTrap Nala)
{
	catRest();

	std::cout << "\033[2J\033[1;1H";
	printCatsFacingEachOther(CYAN, YELLOW, 1);
	Simba.attack("Nala");
	usleep(800000);
	std::cout << "\033[2J\033[1;1H";
	printCatsFacingEachOther(YELLOW, RED, 0);
	Nala.takeDamage(0);
	usleep(800000);

	catRest();

	std::cout << "\033[2J\033[1;1H";
	printCatsFacingEachOther(YELLOW, CYAN, 2);
	Nala.attack("Simba");
	usleep(800000);
	std::cout << "\033[2J\033[1;1H";
	printCatsFacingEachOther(RED, YELLOW, 0);
	Simba.takeDamage(0);
	usleep(800000);
	
	catRest();
}

void endBattle()
{
	sleep(1);
	std::cout << CYAN;
	ClapTrap::typeWrite(".  .  .", 400000);
	std::cout << std::endl;
	ClapTrap::typeWrite("This battle will be eternal, they are not doing any damage!");
	std::cout << std::endl;
	ClapTrap::typeWrite("lets drop this here . . .", 100000);
	std::cout << std::endl;
	sleep(1);
}

int catBattle( void )
{
	std::cout << "\033[2J\033[1;1H";

	ClapTrap Simba("Simba");
	ClapTrap Nala("Nala");
	printCat((sizeof(ClapTrap::cat1) / sizeof(ClapTrap::cat1[0])));
	sleep(1);
	catAction(Simba , Nala);
	catAction(Simba , Nala);
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
	ClapTrap ClapTrap1("ClapTrap1");
	ClapTrap ClapTrap2("ClapTrap2");

	ClapTrap1.attack("ClapTrap2");
	ClapTrap2.takeDamage(10);
	ClapTrap1.beRepaired(2);
	ClapTrap1.beRepaired(123);

	return 0;
}