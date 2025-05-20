/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:55:27 by angnavar          #+#    #+#             */
/*   Updated: 2025/04/21 19:38:27 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Zombie.hpp"

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

int main(void)
{
	std::cout << "se crea el zombie, se anuncia, se destrulle y luego se llama a randomChump\n";
	Zombie* z = newZombie("newZ");
	z->Announce();
	delete z;
	randomChump("rndZ");

	std::cout << "se crea el zombie, se anuncia, se llama a randomChump y luego se destrulle\n";
	z = newZombie("newZ");
	z->Announce();
	randomChump("rndZ");
	delete z;

	std::cout << "se crea el zombie, se llama a randomChump y luego se anuncia y se destrulle\n";
	z = newZombie("newZ");
	randomChump("rndZ");
	z->Announce();
	delete z;

	return 0;
}