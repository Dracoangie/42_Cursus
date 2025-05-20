/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:55:27 by angnavar          #+#    #+#             */
/*   Updated: 2025/04/22 12:23:43 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main(void)
{
	int N = 4;
	std::cout << "Aparece una horda de zombies! \n";
	Zombie *horde = zombieHorde(N,"Paco");

	std::cout << "Los zombis gruñen! \n";
	for (int i = 0; i < N; i++)
		horde[i].Announce();
	
	std::cout << "Los zombis se marchan! \n";
	delete [] horde;
	
	return 0;
}