/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:51:11 by angnavar          #+#    #+#             */
/*   Updated: 2025/10/14 13:22:15 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iostream>
# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter
{
private:
    std::string _name;
    AMateria*   _inventory[4];
    AMateria*   _floor[64];
    int         _floorAmout;

    void clearInventory();
    void copyInventory(Character const & other);

public:
    Character(std::string const & name);
    Character(Character const & other);
    Character & operator=(Character const & other);
    virtual ~Character();

    virtual std::string const & getName() const;
    virtual void equip(AMateria* m);
    virtual void unequip(int index);
    virtual void use(int index, ICharacter& target);
};

#endif
