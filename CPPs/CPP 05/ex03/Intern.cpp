/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 01:33:45 by angnavar          #+#    #+#             */
/*   Updated: 2026/05/26 11:21:04 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{

}

Intern::Intern(Intern const &cpy)
{
	(void)cpy;
}

Intern::~Intern()
{

}

Intern& Intern::operator=(Intern const &cpy)
{
	(void)cpy;
	return *this;
}

AForm* Intern::createShrubberyCreationForm(std::string target)
{
	std::cout << "create Shrubbery Creation Form " << std::endl; 
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(std::string target)
{
	std::cout << "create Robotomy Request Form " << std::endl; 
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(std::string target)
{
	std::cout << "create Presidential Pardon Form " << std::endl; 
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string formName, std::string target)
{
	std::string formNames[3] = {"robotomy request", "shrubbery creation", "presidential pardon"};
	AForm* (Intern::*formCreators[3])(std::string) = {
		&Intern::createRobotomyRequestForm,
		&Intern::createShrubberyCreationForm,
		&Intern::createPresidentialPardonForm
	};

	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
			return (this->*formCreators[i])(target);
	}
	std::cerr << "Error: Form name not recognized." << std::endl;
	return NULL;
}