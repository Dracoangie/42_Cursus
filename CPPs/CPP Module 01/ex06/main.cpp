/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:55:27 by angnavar          #+#    #+#             */
/*   Updated: 2025/04/28 15:29:25 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Harl.hpp"

int main(int argc, char* argv[])
{
	if(argc != 2)
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	else
	{
		Harl harl = Harl();
		harl.complain("DEBUG");
		
	}

	/*
	sleep(1);
	std::cout << "#DEBUG#" << std::endl;
	harl.complain("DEBUG");
	sleep(1);
	std::cout << "#INFO#" << std::endl;
	harl.complain("INFO");
	sleep(1);
	std::cout << "#WARNING#" << std::endl;
	harl.complain("WARNING");
	sleep(1);
	std::cout << "#ERROR#" << std::endl;
	harl.complain("ERROR");
	sleep(1);*/
	return 0;
}
