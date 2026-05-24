/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 21:18:52 by angnavar          #+#    #+#             */
/*   Updated: 2026/05/24 23:19:00 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
	std::string _name;
	int _gradeToSign;
	int _gradeToExecute;
	bool _signed;
	
	Form();
public:
	Form(std::string name, int gradeToSign, int gradeToExecute);
	~Form();
	Form& operator=(Form cpy);
	std::string getName() const;
	std::string getName() ;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	bool getSigned() const ;
	void increment();
	void decrement();
	static void beSigned(Bureaucrat &b, Form &form);
	
};

std::ostream &operator<<( std::ostream &output, Form const &print );