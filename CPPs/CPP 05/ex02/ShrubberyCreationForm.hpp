/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 00:47:59 by angnavar          #+#    #+#             */
/*   Updated: 2026/05/26 10:59:17 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	std::string _target;

	ShrubberyCreationForm();
public:
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(ShrubberyCreationForm const &cpy);
	~ShrubberyCreationForm();
	ShrubberyCreationForm& operator=(ShrubberyCreationForm const &cpy);
	virtual void execute(const Bureaucrat & executor) const;
};