/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 21:31:45 by angnavar          #+#    #+#             */
/*   Updated: 2026/05/26 11:02:20 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute)
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
AForm::~AForm()
{

}

AForm& AForm::operator=(AForm const &cpy)
{
	_name = cpy.getName();
	_gradeToSign = cpy.getGradeToSign();
	_gradeToExecute = cpy.getGradeToExecute();
	_signed = cpy.getSigned();
	return *this;
}

std::string AForm::getName() const
{
	return _name;
}
int AForm::getGradeToSign() const
{
	return _gradeToSign;
}
int AForm::getGradeToExecute() const
{
	return _gradeToExecute;
}
bool AForm::getSigned() const
{
	return _signed;
}

void AForm::beSigned(Bureaucrat &b, AForm &form)
{
	if(b.getGrade() > form.getGradeToSign())
		throw std::runtime_error("Form::GradeTooLowException");
	else
		form._signed = true;
}


std::ostream &operator<<(std::ostream &output, AForm const &form)
{
	output << "Form " << form.getName()
		<< " | signed: " << (form.getSigned() ? "true" : "false")
		<< " | grade to sign: " << form.getGradeToSign()
		<< " | grade to execute: " << form.getGradeToExecute();
	return output;
}