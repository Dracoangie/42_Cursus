/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:59:30 by angnavar          #+#    #+#             */
/*   Updated: 2025/04/22 13:28:14 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
};

Weapon::Weapon(std::string type)
{
	_type = type;
};

Weapon::~Weapon()
{
};

void Weapon::setType(std::string type)
{
	std::cout << "\033[1;33m" << "Weapon of type: " << _type;
	_type = type;
	std::cout << ". Changes to: " << _type << ".\033[0m\n";
};

std::string Weapon::getType()
{
	return(_type);
};