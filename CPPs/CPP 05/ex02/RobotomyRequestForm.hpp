/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 00:53:42 by angnavar          #+#    #+#             */
/*   Updated: 2026/05/26 10:59:14 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
	std::string _target;
	RobotomyRequestForm();
public:
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm const &cpy);
	~RobotomyRequestForm();
	RobotomyRequestForm& operator=(RobotomyRequestForm const &cpy);
	virtual void execute(const Bureaucrat & executor) const;
};