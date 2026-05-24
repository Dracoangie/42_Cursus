/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 00:34:05 by angnavar          #+#    #+#             */
/*   Updated: 2026/05/24 23:24:12 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

class PresidentialPardonForm : public AForm
{
	std::string _target;
	PresidentialPardonForm();
public:
	PresidentialPardonForm(PresidentialPardonForm const &cpy);
	PresidentialPardonForm(std::string target);
	~PresidentialPardonForm();
	PresidentialPardonForm& operator=(PresidentialPardonForm const &cpy);
	void execute(const Bureaucrat & executor) const;
};