/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 20:41:40 by angnavar          #+#    #+#             */
/*   Updated: 2025/10/14 13:44:51 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"

static void printLine(const std::string& s)
{
    std::cout << "\n===== " << s << " =====" << std::endl;
}

int main()
{
    printLine("Create MateriaSource and learn templates");
    IMateriaSource* src = new MateriaSource();
    AMateria* proto = new Ice();
    src->learnMateria(proto);
    delete proto;
    proto = new Cure();
    src->learnMateria(proto);
    delete proto;

    printLine("Create characters");
    Character* me = new Character("me");
    ICharacter* bob = new Character("bob");

    printLine("Create materias from source");
    AMateria* m1 = src->createMateria("ice");
    AMateria* m2 = src->createMateria("cure");
    AMateria* m3 = src->createMateria("ice");
    AMateria* m4 = src->createMateria("cure");
    AMateria* extra = src->createMateria("ice");

    std::cout << "Equip four materias in order" << std::endl;
    me->equip(m1);
    me->equip(m2);
    me->equip(m3);
    me->equip(m4);

    printLine("Try to equip when inventory is full");
    me->equip(extra);
    delete extra;

    printLine("Use materias of 'me' on 'bob'");
    me->use(0, *bob);
    me->use(1, *bob);
    me->use(2, *bob);
    me->use(3, *bob);

    printLine("Use with invalid indices");
    me->use(-1, *bob);
    me->use(42, *bob);

    printLine("Unequip a slot and equip a new one");
    me->unequip(1);
    me->use(1, *bob);
    AMateria* m5 = src->createMateria("ice");
    me->equip(m5);
    me->use(1, *bob);

    printLine("Deep copy Character");
    Character copy(*me);
    std::cout << "Use copy on bob" << std::endl;
    copy.use(0, *bob);
    copy.use(1, *bob);
    copy.use(2, *bob);
    copy.use(3, *bob);

    printLine("Unequip in copy does not affect original");
    copy.unequip(2);
    std::cout << "copy.use(2): "; copy.use(2, *bob);
    std::cout << "me.use(2): ";   me->use(2, *bob);

    printLine("Delete all");
    delete bob;
    delete me;
    delete src;
    return 0;
}