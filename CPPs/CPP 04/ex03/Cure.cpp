/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 13:18:07 by angnavar          #+#    #+#             */
/*   Updated: 2025/10/14 13:19:15 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure") {}
Cure::Cure(Cure const & other) : AMateria(other) {}
Cure::~Cure() {}
Cure & Cure::operator=(Cure const & other)
{
	AMateria::operator=(other);
	return *this;
}

AMateria* Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
	std::cout << BGREEN << "* heals " << target.getName() << "'s wounds *" << RESET << std::endl;
}