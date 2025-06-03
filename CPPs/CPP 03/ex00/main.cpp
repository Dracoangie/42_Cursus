/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:31:55 by angnavar          #+#    #+#             */
/*   Updated: 2025/05/20 13:54:10 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"
# include <iomanip>

const std::string cat1[] = {
	"                            ,      ",
	"                          _/((     ",
	"                 _.---. .'   `\\   ",
	"               .'      `     ^ T=  ",
	"              /     \\       .--'  ",
	"             |      /       )'-.   ",
	"             ; ,   <__..-(   '-.)  ",
	"             \\ \\-.__)    ``--._) ",
	"              '.'-.__.-.           ",
	"                 '-...-'           "
};

const std::string cat2[] = {
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
const size_t cat_lines = sizeof(cat1) / sizeof(cat1[0]);

void printCatsFacingEachOther (std::string color1, std::string color2)
{
	for (size_t i = 0; i < cat_lines; ++i) {
		std::cout << color1 << std::left  << std::setw(40) << cat1[i] << std::setw(5) << RESET 
				<< color2 << std::right << cat2[i] << RESET << std::endl;
	}
}

void printCat(const std::string cat[], size_t lines)
{
	for (size_t i = 0; i < lines; ++i)
		std::cout << YELLOW << cat[i] << RESET << std::endl;
}

void catRest()
{
	std::cout << "\033[2J\033[1;1H";
	printCatsFacingEachOther(YELLOW, YELLOW);
	usleep(400000);

	std::cout << "\033[2J\033[1;1H";
	std::cout << std::endl;
	printCatsFacingEachOther(YELLOW, YELLOW);
	usleep(400000);

	std::cout << "\033[2J\033[1;1H";
	printCatsFacingEachOther(YELLOW, YELLOW);
	usleep(400000);
}

void catAction(ClapTrap Simba, ClapTrap Nala)
{
	catRest();

	std::cout << "\033[2J\033[1;1H";
	printCatsFacingEachOther(CYAN, YELLOW);
	Simba.attack("Nala");
	usleep(800000);
	std::cout << "\033[2J\033[1;1H";
	printCatsFacingEachOther(YELLOW, RED);
	Nala.takeDamage(0);
	usleep(800000);

	catRest();

	std::cout << "\033[2J\033[1;1H";
	printCatsFacingEachOther(YELLOW, CYAN);
	Nala.attack("Simba");
	usleep(800000);
	std::cout << "\033[2J\033[1;1H";
	printCatsFacingEachOther(RED, YELLOW);
	Simba.takeDamage(0);
	usleep(800000);
	
	catRest();
}

int main( void )
{
	std::cout << "\033[2J\033[1;1H";

	ClapTrap Simba("Simba");
	ClapTrap Nala("Nala");
	printCat(cat1, cat_lines);
	sleep(1);
	catAction(Simba , Nala);
	catAction(Simba , Nala);

	return 0;
}