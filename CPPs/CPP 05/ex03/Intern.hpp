/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 01:33:25 by angnavar          #+#    #+#             */
/*   Updated: 2026/05/19 01:39:57 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	AForm* createShrubberyCreationForm(std::string target);
	AForm* createRobotomyRequestForm(std::string target);
	AForm* createPresidentialPardonForm(std::string target);

public:
	Intern();
	~Intern();
	Intern& operator=(Intern const &cpy);
	AForm* makeForm(std::string formName, std::string target);
};