/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 21:31:45 by angnavar          #+#    #+#             */
/*   Updated: 2025/12/02 22:24:50 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade)
{
	this->_name = name;
		try
	{
		if(_grade < 1){
			this->_grade = 1;
            throw std::runtime_error("GradeTooHighException");}
		else if(_grade > 150){
			this->_grade = 150;
            throw std::runtime_error("GradeTooLowException");}
		else
			this->_grade = grade;
	}
	catch(const std::runtime_error& e)
	{
		 std::cout << e.what() << std::endl;
	}
}
Bureaucrat::~Bureaucrat()
{

}

Bureaucrat& Bureaucrat::operator=(Bureaucrat cpy)
{
	_name = cpy.getName();
	_grade = cpy.getGrade();
	return *this;
}

std::string Bureaucrat::getName()
{
	return _name;
}
int Bureaucrat::getGrade()
{
	return _grade;
}
void Bureaucrat::increment()
{
	try
	{
		--_grade;
		if(_grade < 1){
			this->_grade = 1;
            throw std::runtime_error("GradeTooHighException");}
	}
	catch(const std::runtime_error& e)
	{
		 std::cout << e.what() << std::endl;
	}
}
void Bureaucrat::decrement()
{
	try
	{
		++_grade;
		if(_grade > 150){
			this->_grade = 150;
            throw std::runtime_error("GradeTooLowException");}
	}
	catch(const std::runtime_error& e)
	{
		 std::cout << e.what() << std::endl;
	}
}


std::ostream &operator<<( std::ostream &output, Bureaucrat &print )
{ 
	output << print.getName() << ", bureaucrat grade" << print.getGrade() << "." << std::endl;
	return output;            
}