/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 01:12:49 by angnavar          #+#    #+#             */
/*   Updated: 2026/05/19 01:17:53 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <iostream>

int main()
{
	std::cout << "\n===== SHRUBBERY TEST =====\n" << std::endl;

	try
	{
		Bureaucrat boss("Boss", 1);
		ShrubberyCreationForm tree("home");

		std::cout << boss << std::endl;
		std::cout << tree << std::endl;

		boss.signForm(tree);
		boss.executeForm(tree);

		std::cout << "Check file: home_shrubbery" << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}


	std::cout << "\n===== ROBOTOMY TEST =====\n" << std::endl;

	try
	{
		Bureaucrat robotGuy("RobotGuy", 1);
		RobotomyRequestForm robot("Bender");

		robotGuy.signForm(robot);

		for (int i = 0; i < 5; i++)
			robotGuy.executeForm(robot);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}


	std::cout << "\n===== PRESIDENTIAL TEST =====\n" << std::endl;

	try
	{
		Bureaucrat president("President", 1);
		PresidentialPardonForm pardon("Arthur Dent");

		president.signForm(pardon);
		president.executeForm(pardon);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}


	std::cout << "\n===== UNSIGNED FORM TEST =====\n" << std::endl;

	try
	{
		Bureaucrat boss("Boss", 1);
		ShrubberyCreationForm unsignedForm("garden");

		boss.executeForm(unsignedForm);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}


	std::cout << "\n===== GRADE TOO LOW TEST =====\n" << std::endl;

	try
	{
		Bureaucrat intern("Intern", 150);
		PresidentialPardonForm pardon("Marvin");

		intern.signForm(pardon);
		intern.executeForm(pardon);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}