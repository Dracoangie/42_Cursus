/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 20:43:25 by angnavar          #+#    #+#             */
/*   Updated: 2025/10/14 13:02:43 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() : type("") {}
AMateria::AMateria(std::string const & t) : type(t) {}
AMateria::AMateria(AMateria const & other) : type(other.type) {}
AMateria & AMateria::operator=(AMateria const & other)
{
    if (this != &other) type = other.type;
    return *this;
}
AMateria::~AMateria() {}

std::string const & AMateria::getType() const 
{ 
	return type;
}

void AMateria::use(ICharacter& target) 
{
    std::cout << "No effect on " << target.getName() << std::endl;
}
