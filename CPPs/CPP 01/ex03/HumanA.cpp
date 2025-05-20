/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:47:46 by angnavar          #+#    #+#             */
/*   Updated: 2025/04/22 18:21:18 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon)
	: _name(name), _weapon(weapon)
{
	std::cout << "\033[1;32m" << _name <<" has now the weapon of type: ";
	std::cout << _weapon.getType() << ".\033[0m\n";
}


HumanA::~HumanA()
{
};

void HumanA::setType(std::string type)
{
	_weapon.setType(type);
};

void HumanA::attack()
{
	std::cout << "\033[1;31m" << _name << " is atacking with: " << _weapon.getType() << "\033[0m\n";
};