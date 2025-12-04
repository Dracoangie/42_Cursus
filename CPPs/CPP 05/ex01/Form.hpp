/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 21:18:52 by angnavar          #+#    #+#             */
/*   Updated: 2025/12/04 13:47:47 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Form
{
	std::string _name;
	int _grade;
	
public:
	Form(std::string name, int grade);
	~Form();
	Form& operator=(Form cpy);
	std::string getName();
	int getGrade();
	void increment();
	void decrement();
	
	friend std::ostream &operator<<( std::ostream &output, Form &print );
};