/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:10:22 by angnavar          #+#    #+#             */
/*   Updated: 2025/04/10 16:23:55 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"


void PhoneBook::Intro(void)
{

	std::cout << "Welcome to your ";
	std::cout << "\033[31mA\033[0m";
	std::cout << "\033[32mW\033[0m";
	std::cout << "\033[33mE\033[0m";
	std::cout << "\033[34mS\033[0m";
	std::cout << "\033[35mO\033[0m";
	std::cout << "\033[36mM\033[0m";
	std::cout << "\033[91mE\033[0m";
	std::cout << " PhoneBook!" << '\n';
	std::cout << "You can: \n";
	std::cout << "\033[32mADD\033[0m: add new contact\n";
	std::cout << "\033[36mSEARCH\033[0m: search for an existing contact\n";
	std::cout << "\033[31mEXIT\033[0m: exit the program\n";
}

std::string PhoneBook::NewContactInfo(std::string info)
{
	std::string str;
	bool isASCII;

	while (true)
	{
		isASCII = true;
		std::cout << "Enter " << info;
		std::getline(std::cin, str);

		if (str.empty())
		{
			std::cout << "\033[33mEnter something please\033[0m \033[31m>:( \033[0m\n";
			continue;
		}

		for (size_t i = 0; i < str.length(); ++i)
		{
			if (static_cast<unsigned char>(str[i]) < 32 || static_cast<unsigned char>(str[i]) > 126)
			{
				isASCII = false;
				break;
			}
		}
		if (!isASCII)
		{
			std::cout << "\033[33mEnter ASCII characters only please\033[0m\n";
			continue;
		}
		return (str);
	}
}


void PhoneBook::NewContact()
{
	ContactInfo info;
	
	std::cout << "Adding new contact... \n";
	info.firstName = NewContactInfo("first name: ");
	info.lastName = NewContactInfo("last name: ");
	info.phoneNumber = NewContactInfo("phone number: ");
	info.darkestSecret = NewContactInfo("darkest secret: ");
	if (contactCount < 8)
	{
		contacts[contactCount].SetContact(info);
		++contactCount;
		std::cout << "\033[32mNew contact added!\033[0m \n";
	}
	else
	{
		contacts[firstContact].SetContact(info);
		++firstContact;
		if(firstContact >= 8)
			firstContact = 0;
		std::cout << "\033[31mLast contact deleted...\033[0m \n";
		std::cout << "\033[32mNew contact added!\033[0m \n";
	}
}

std::string PhoneBook::TableFormat(const std::string& str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	else
		return std::string(10 - str.length(), ' ') + str;
}
void PhoneBook::PrintTable()
{
	ContactInfo info;
	
	std::cout << "    +----------+----------+----------+----------+"<< '\n';
	std::cout << "    | firstName|  LastName|    Number|    Secret|"<< '\n';
	std::cout << "+---+----------+----------+----------+----------+"<< '\n';
	for (int i = 0; i < contactCount; i++)
	{
		std::cout << "| " << i +1;
		info = contacts[i].GetContactEnum();
		std::cout << " |"
				<< TableFormat(info.firstName) << "|"
				<< TableFormat(info.lastName) << "|"
				<< TableFormat(info.phoneNumber) << "|"
				<< TableFormat(info.darkestSecret) << "|" << '\n';
	}
	for (int i = 0; i < 8 - contactCount; i++)
	{
		std::cout << "| " << i + contactCount +1;
		std::cout << " |          |          |          |          |"<< '\n';
	}
	std::cout << "+---+----------+----------+----------+----------+"<< '\n';
};

void PhoneBook::SeeContact(int index)
{
	ContactInfo info;
	info = contacts[index].GetContactEnum();
	std::cout  <<  "\033[36mFirst name: \033[0m" << info.firstName << '\n' 
				<< "\033[36mLast name: \033[0m" << info.lastName << '\n' 
				<< "\033[36mPhone number: \033[0m" << info.phoneNumber << '\n' 
				<< "\033[36mDarkest secret: \033[0m" << info.darkestSecret << '\n';
}


void PhoneBook::SeePhoneBook(void)
{
	std::string	str;
	int	index;

	this->PrintTable();
	while (true)
	{
		std::cout << "index of the contact to search: ";
		std::getline(std::cin, str);

		if (str == "Q")
			break;

		std::istringstream iss(str);
		if (!(iss >> index)) {
			std::cout << "\033[33mInvalid index. Please try again.\033[0m\n";
			continue;
		}
		if(index -1 < contactCount && index >= 0)
			SeeContact(index -1);
		else
			std::cout << "\033[33mIndex out of range. Please try again.\033[0m\n";
	}
}

PhoneBook::PhoneBook()
{
	this->contactCount = 0;
	this->firstContact = 0;
};
PhoneBook::~PhoneBook(){};