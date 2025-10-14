/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 13:17:05 by angnavar          #+#    #+#             */
/*   Updated: 2025/10/14 13:19:40 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() : AMateria("ice") {}
Ice::Ice(Ice const & other) : AMateria(other) {}
Ice::~Ice() {}
Ice & Ice::operator=(Ice const & other)
{
    AMateria::operator=(other);
    return *this;
}

AMateria* Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
    std::cout << BCYAN << "* shoots an ice bolt at " << target.getName() << " *" << RESET << std::endl;
}
