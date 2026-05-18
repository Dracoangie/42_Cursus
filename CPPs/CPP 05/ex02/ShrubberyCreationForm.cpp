/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 00:49:10 by angnavar          #+#    #+#             */
/*   Updated: 2026/05/19 01:20:27 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Creation", 145, 137), _target(target)
{

}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const &cpy)
{
	AForm::operator=(cpy);
	_target = cpy._target;
	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat & executor) const
{
	if (!getSigned())
		throw std::runtime_error("FormNotSignedException");
	else if (executor.getGrade() > getGradeToExecute())
		throw std::runtime_error("GradeTooLowException");
	else
	{
		std::ofstream file((_target + "_shrubbery").c_str());
		if (file.is_open())
		{
			file << "       _-_" << std::endl;
			file << "    /~~   ~~\\" << std::endl;
			file << " /~~         ~~\\" << std::endl;
			file << "{               }" << std::endl;
			file << " \\  _-     -_  /" << std::endl;
			file << "   ~  \\\\ //  ~" << std::endl;
			file << "_- -   | | _- _" << std::endl;
			file << "  _ -  | |   -_" << std::endl;
			file << "      // \\\\" << std::endl;
			file.close();
		}
		else
			std::cerr << "Error: Could not create file." << std::endl;
	}
}