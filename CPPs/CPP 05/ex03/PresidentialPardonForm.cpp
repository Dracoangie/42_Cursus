/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 00:37:42 by angnavar          #+#    #+#             */
/*   Updated: 2026/05/26 11:17:28 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon", 25, 5)
{

}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &cpy) : AForm("Presidential Pardon", 25, 5)
{
	AForm::operator=(cpy);
	_target = cpy._target;
}
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon", 25, 5), _target(target)
{

}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const &cpy)
{
	AForm::operator=(cpy);
	_target = cpy._target;
	return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat & executor) const
{
	if (!getSigned())
		throw std::runtime_error("PresidentialPardonForm::NotSignedException");
	else if (executor.getGrade() > getGradeToExecute())
		throw std::runtime_error("PresidentialPardonForm::GradeTooLowException");
	else
		std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}