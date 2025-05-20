/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:02:44 by angnavar          #+#    #+#             */
/*   Updated: 2025/04/22 18:21:24 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	_name = name;
};

HumanB::~HumanB()
{
};

void HumanB::setWeapon(Weapon *weapon)
{
	std::cout << "\033[1;32m" << _name <<" has now the weapon of type: ";
	_weapon = weapon;
	std::cout << _weapon->getType() << ".\033[0m\n";
};

void HumanB::attack()
{
	std::cout << "\033[1;31m" << _name << " is atacking with: " << _weapon->getType() << "\033[0m\n";
};