/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 21:18:52 by angnavar          #+#    #+#             */
/*   Updated: 2025/12/02 21:32:04 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Bureaucrat
{
	std::string _name;
	int _grade;
	
public:
	Bureaucrat(std::string name, int grade);
	~Bureaucrat();
	Bureaucrat& operator=(Bureaucrat cpy);
	std::string getName();
	int getGrade();
	void increment();
	void decrement();
	
	friend std::ostream &operator<<( std::ostream &output, Bureaucrat &print );
};