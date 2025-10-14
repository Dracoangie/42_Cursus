/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 13:03:49 by angnavar          #+#    #+#             */
/*   Updated: 2025/10/14 13:22:13 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const & name)
: _name(name), _floorAmout(0)
{
    for (int i = 0; i < 4; ++i)
		_inventory[i] = 0;
    for (int i = 0; i < 64; ++i)
		_floor[i] = 0;
}

Character::Character(Character const & other)
: _name(other._name), _floorAmout(0)
{
    for (int i = 0; i < 4; ++i)
		_inventory[i] = 0;
    for (int i = 0; i < 64; ++i)
		_floor[i] = 0;
    copyInventory(other);
}

Character & Character::operator=(Character const & other)
{
    if (this != &other)
	{
        _name = other._name;
        clearInventory();
        copyInventory(other);
    }
    return *this;
}

Character::~Character()
{
    clearInventory();
    for (int i = 0; i < _floorAmout; ++i)
	{
        delete _floor[i];
        _floor[i] = 0;
    }
}

void Character::clearInventory()
{
    for (int i = 0; i < 4; ++i)
	{
        if (_inventory[i])
		{
            delete _inventory[i];
            _inventory[i] = 0;
        }
    }
}

void Character::copyInventory(Character const & other)
{
    for (int i = 0; i < 4; ++i)
	{
        if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
        else
			_inventory[i] = 0;
    }
}

std::string const & Character::getName() const 
{ 
	return _name;
}

void Character::equip(AMateria* m)
{
    if (!m)
		return;
    for (int i = 0; i < 4; ++i)
	{
        if (_inventory[i] == 0)
		{
            std::cout << GREEN << "Equipped materia to inventory!" << RESET << std::endl;
            _inventory[i] = m;
            return;
        }
    }
	std::cout << RED << "Inventory full, cannot equip more materia!" << RESET << std::endl;
}

void Character::unequip(int index)
{
    if (index < 0 || index > 3)
	{
		std::cout << RED << "Invalid index, cannot unequip materia!" << RESET << std::endl;
		return;
	}
    if (_inventory[index] == 0)
	{
		std::cout << RED << "Inventory empty, cannot unequip materia!" << RESET << std::endl;
		return;
	}
    if (_floorAmout < 64)
	{
        _floor[_floorAmout++] = _inventory[index];
    }
	std::cout << GREEN << "Unequipped materia from inventory!" << RESET << std::endl;
    _inventory[index] = 0;
}

void Character::use(int index, ICharacter& target)
{
    if (index < 0 || index > 3)
	{
		std::cout << RED << "Invalid index, cannot use materia!" << RESET << std::endl;
		return;
	}
    if (_inventory[index])
		_inventory[index]->use(target);
}
