/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 21:31:45 by angnavar          #+#    #+#             */
/*   Updated: 2026/05/19 01:19:16 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade)
{
	this->_name = name;
	if(grade < 1){
		this->_grade = 1;
		throw std::runtime_error("GradeTooHighException");}
	else if(grade > 150){
		this->_grade = 150;
		throw std::runtime_error("GradeTooLowException");}
	else
		this->_grade = grade;
}
Bureaucrat::~Bureaucrat()
{

}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const &cpy)
{
	_name = cpy.getName();
	_grade = cpy.getGrade();
	return *this;
}

std::string Bureaucrat::getName() const
{
	return _name;
}
int Bureaucrat::getGrade() const
{
	return _grade;
}
void Bureaucrat::increment()
{
	--_grade;
	if(_grade < 1){
		this->_grade = 1;
		throw std::runtime_error("GradeTooHighException");}
}
void Bureaucrat::decrement()
{
	++_grade;
	if(_grade > 150){
		this->_grade = 150;
		throw std::runtime_error("GradeTooLowException");
	}
}

void Bureaucrat::signForm(AForm &form)
{
	try {
		AForm::beSigned(*this, form);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form) const
{
	try {
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << _name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}


std::ostream &operator<<( std::ostream &output, Bureaucrat &print )
{ 
	output << print.getName() << ", bureaucrat grade " << print.getGrade() << "." << std::endl;
	return output;            
}