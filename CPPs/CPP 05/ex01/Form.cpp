/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 21:31:45 by angnavar          #+#    #+#             */
/*   Updated: 2025/12/04 13:48:39 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string name, int grade)
{
	this->_name = name;
	if(grade < 1){
		this->_grade = 1;
		throw std::runtime_error("Form::GradeTooHighException");}
	else if(grade > 150){
		this->_grade = 150;
		throw std::runtime_error("Form::GradeTooLowException");}
	else
		this->_grade = grade;
}
Form::~Form()
{

}

Form& Form::operator=(Form cpy)
{
	_name = cpy.getName();
	_grade = cpy.getGrade();
	return *this;
}

std::string Form::getName()
{
	return _name;
}
int Form::getGrade()
{
	return _grade;
}
void Form::increment()
{
	--_grade;
	if(_grade < 1){
		this->_grade = 1;
		throw std::runtime_error("Form::GradeTooHighException");}
}
void Form::decrement()
{
	++_grade;
	if(_grade > 150){
		this->_grade = 150;
		throw std::runtime_error("Form::GradeTooLowException");
	}
}


std::ostream &operator<<( std::ostream &output, Form &print )
{ 
	output << print.getName() << ", bureaucrat grade " << print.getGrade() << "." << std::endl;
	return output;            
}