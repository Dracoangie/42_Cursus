/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:55:25 by angnavar          #+#    #+#             */
/*   Updated: 2025/04/21 20:22:32 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#include <iostream>

Zombie::Zombie(std::string name)
{
	_name = name;
	std::cout << "\033[1;32m" << _name << ": AppeaaaaaarrrzzzZ...\033[0m\n";
}

Zombie::~Zombie()
{
	std::cout << "\033[1;31m" << _name << ": ByyyyyyeeezzzZ...\033[0m\n";
}

void Zombie::Announce()
{
	std::cout << "\033[1;35m" << _name << ": BraiiiiiiinnnzzzZ...\033[0m\n";
}
