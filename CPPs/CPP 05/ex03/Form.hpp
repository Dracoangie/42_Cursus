/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 21:18:52 by angnavar          #+#    #+#             */
/*   Updated: 2026/05/19 01:19:13 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>

class Bureaucrat;

class AForm
{
private:
	std::string _name;
	int _gradeToSign;
	int _gradeToExecute;
	bool _signed;

public:
	AForm(std::string name, int gradeToSign, int gradeToExecute);
	virtual ~AForm();

	AForm& operator=(AForm const &cpy);

	int getGradeToSign() const;
	int getGradeToExecute() const;
	bool getSigned() const;
	std::string getName() const;

	static void beSigned(Bureaucrat &b, AForm &form);

	virtual void execute(Bureaucrat const &executor) const = 0;

	friend std::ostream &operator<<(std::ostream &output, AForm const &print);
};

#endif