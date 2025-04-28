/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:27:46 by angnavar          #+#    #+#             */
/*   Updated: 2025/04/28 15:28:08 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	std::cout << "Harl has come! Do you know Harl? We all do, don’t we? In case you don’t, he complains a lot. But thats your problem now, good luck!" << std::endl;
};
Harl::~Harl()
{
	std::cout << "Finally he leave! Good job, you survived to Harl!" << std::endl;
};

// private

void Harl::debug()
{
	std::cout << "\033[1;35mI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\033[0m" << std::endl;
};

void Harl::info()
{
	std::cout << "\033[1;36mI cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\033[0m" << std::endl;
};

void Harl::warning()
{
	std::cout << "\033[1;33mI think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month.\033[0m" << std::endl;
};

void Harl::error()
{
	std::cout << "\033[1;31mThis is unacceptable! I want to speak to the manager now.\033[0m" << std::endl;
};

// public

void Harl::complain(std::string level)
{
	typedef void (Harl::*Func)();
	Func complains[] = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

	std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*complains[i])();
			return;
		}
	}
};

void Harl::complainFrom(std::string level)
{
	
}