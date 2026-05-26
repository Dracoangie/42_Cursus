/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 01:12:49 by angnavar          #+#    #+#             */
/*   Updated: 2026/05/26 11:12:37 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

#include <iostream>
#include <ctime>

int main()
{
    std::srand(std::time(NULL));

	Intern someRandomIntern;
	AForm* rrf;
	Bureaucrat boss("Boss", 1);
	rrf = someRandomIntern.makeForm("shrubbery creation", "Tree");
	rrf->beSigned(boss, *rrf);
	rrf->execute(boss);
	delete rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Robot");
	rrf->beSigned(boss, *rrf);
	rrf->execute(boss);
	delete rrf;
	rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
	rrf->beSigned(boss, *rrf);
	rrf->execute(boss);
	delete rrf;
}