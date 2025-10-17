/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 13:19:54 by angnavar          #+#    #+#             */
/*   Updated: 2025/10/17 11:11:24 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; ++i)
		materia[i] = 0;
}

MateriaSource::MateriaSource(MateriaSource const & other)
{
    for (int i = 0; i < 4; ++i)
		materia[i] = 0;
    for (int i = 0; i < 4; ++i)
	{
        if (other.materia[i])
			materia[i] = other.materia[i]->clone();
    }
}

MateriaSource & MateriaSource::operator=(MateriaSource const & other)
{
    if (this != &other)
	{
        for (int i = 0; i < 4; ++i)
		{
            delete materia[i];
            materia[i] = 0;
        }
        for (int i = 0; i < 4; ++i)
            if (other.materia[i]) materia[i] = other.materia[i]->clone();
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; ++i)
	{
        delete materia[i];
        materia[i] = 0;
    }
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (!m)
		return;
    for (int i = 0; i < 4; ++i)
	{
        if (materia[i] == 0)
		{
			std::cout << GREEN << "Learned new materia!" << RESET << std::endl;
            materia[i] = m->clone();
            return;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; ++i)
	{
        if (materia[i] && materia[i]->getType() == type)
		{
			std::cout << CYAN << "Created materia of type: " << type << RESET << std::endl;
            return materia[i]->clone();
        }
    }
    return 0;
}
