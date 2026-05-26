/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 00:53:55 by angnavar          #+#    #+#             */
/*   Updated: 2026/05/26 11:17:37 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request", 72, 45)
{

}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &cpy) : AForm("Robotomy Request", 72, 45)
{
	AForm::operator=(cpy);
	_target = cpy._target;
}
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request", 72, 45), _target(target)
{

}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const &cpy)
{
	AForm::operator=(cpy);
	_target = cpy._target;
	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat & executor) const
{
	if (!getSigned())
		throw std::runtime_error("RobotomyRequestForm::NotSignedException");
	else if (executor.getGrade() > getGradeToExecute())
		throw std::runtime_error("RobotomyRequestForm::GradeTooLowException");
	else
	{
		std::cout << "Bzzzz... Bzzzz... Bzzzz..." << std::endl;
		if (rand() % 2)
			std::cout << _target << " has been robotomized successfully." << std::endl;
		else
			std::cout << "Robotomy failed on " << _target << "." << std::endl;
	}
}