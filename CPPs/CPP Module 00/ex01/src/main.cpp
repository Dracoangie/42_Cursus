/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:56:51 by angnavar          #+#    #+#             */
/*   Updated: 2025/04/10 13:09:00 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

int main()
{
	PhoneBook 	phoneBook;
	std::string	command;

	phoneBook.Intro();
    while (true)
    {
        std::cout << "Please enter a command: ";
        std::getline(std::cin, command);
		if(command.compare("ADD") == 0)
			phoneBook.NewContact();
		else if(command.compare("SEARCH") == 0)
			phoneBook.SeePhoneBook();
		else if(command.compare("EXIT") == 0)
			break;
    }
    return (0);
}