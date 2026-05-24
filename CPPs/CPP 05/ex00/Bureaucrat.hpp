/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 21:18:52 by angnavar          #+#    #+#             */
/*   Updated: 2026/05/24 23:13:50 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
	std::string _name;
	int _grade;
	
	Bureaucrat();
public:
	Bureaucrat(std::string name, int grade);
	~Bureaucrat();
	Bureaucrat& operator=(Bureaucrat cpy);
	std::string getName() const;
	int getGrade() const;
	void increment();
	void decrement();
};

std::ostream &operator<<( std::ostream &output, Bureaucrat const &print );

#endif