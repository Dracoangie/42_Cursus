/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 21:31:45 by angnavar          #+#    #+#             */
/*   Updated: 2026/05/24 23:19:01 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(){}

Form::Form(std::string name, int gradeToSign, int gradeToExecute)
{

	this->_name = name;
	if(gradeToSign > 150){
		this->_gradeToSign = 150;
		throw std::runtime_error("Form::GradeTooLowException");}
	else
		this->_gradeToSign = gradeToSign;
	if(gradeToExecute > 150){
		this->_gradeToExecute = 150;
		throw std::runtime_error("Form::GradeTooLowException");}
	else
		this->_gradeToExecute = gradeToExecute;
	this->_signed = false;
}
Form::~Form()
{

}

Form& Form::operator=(Form cpy)
{
	_name = cpy.getName();
	_gradeToSign = cpy.getGradeToSign();
	_gradeToExecute = cpy.getGradeToExecute();
	_signed = cpy.getSigned();
	return *this;
}

std::string Form::getName() const
{
	return _name;
}
std::string Form::getName()
{
	return _name;
}
int Form::getGradeToSign() const
{
	return _gradeToSign;
}
int Form::getGradeToExecute() const
{
	return _gradeToExecute;
}
bool Form::getSigned() const
{
	return _signed;
}
void Form::increment()
{
	--_gradeToSign;
	if(_gradeToSign < 1){
		this->_gradeToSign = 1;
		throw std::runtime_error("Form::GradeTooHighException");}
}
void Form::decrement()
{
	++_gradeToSign;
	if(_gradeToSign > 150){
		this->_gradeToSign = 150;
		throw std::runtime_error("Form::GradeTooLowException");
	}
}

void Form::beSigned(Bureaucrat &b, Form &form)
{
	if(b.getGrade() > form.getGradeToSign())
		throw std::runtime_error("Form::GradeTooLowException");
	else
		form._signed = true;
}


std::ostream &operator<<(std::ostream &output, Form const &form)
{
	output << "Form " << form.getName()
		<< " | signed: " << (form.getSigned() ? "true" : "false")
		<< " | grade to sign: " << form.getGradeToSign()
		<< " | grade to execute: " << form.getGradeToExecute();
	return output;
}