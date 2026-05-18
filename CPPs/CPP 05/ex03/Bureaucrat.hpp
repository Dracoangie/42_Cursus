/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 21:18:52 by angnavar          #+#    #+#             */
/*   Updated: 2026/05/19 01:16:52 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class AForm;

class Bureaucrat
{
	std::string _name;
	int _grade;

public:
	Bureaucrat(std::string name, int grade);
	~Bureaucrat();
	Bureaucrat& operator=(Bureaucrat const &cpy);

	std::string getName() const;
	int getGrade() const;

	void increment();
	void decrement();
	void signForm(AForm &form);
	void executeForm(AForm const &form) const;

	friend std::ostream &operator<<(std::ostream &output, Bureaucrat &print);
};

#endif