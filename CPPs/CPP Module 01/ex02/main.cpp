/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:55:27 by angnavar          #+#    #+#             */
/*   Updated: 2025/04/22 12:37:55 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "The memory address: \n"
		<< "of the string: " << &str  << "\n"
		<< "held by stringPTR: " << stringPTR  << "\n"
		<< "held by stringREF: " << &stringREF  << "\n\n";

	std::cout << "The value: \n"
		<< "of the string: " << str  << "\n"
		<< "pointed to by stringPTR: " << *stringPTR  << "\n"
		<< "pointed to by stringREF: " << stringREF  << "\n";
}