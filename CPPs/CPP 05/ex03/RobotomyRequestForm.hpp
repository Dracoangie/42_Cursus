/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 00:53:42 by angnavar          #+#    #+#             */
/*   Updated: 2026/05/19 01:11:56 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
	std::string _target;
public:
	RobotomyRequestForm(std::string target);
	~RobotomyRequestForm();
	RobotomyRequestForm& operator=(RobotomyRequestForm const &cpy);
	virtual void execute(const Bureaucrat & executor) const;
};