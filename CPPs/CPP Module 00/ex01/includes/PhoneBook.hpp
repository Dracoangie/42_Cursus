/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:02:39 by angnavar          #+#    #+#             */
/*   Updated: 2025/04/10 13:18:26 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include <sstream>
//# include <iomanip>

# include "Contact.hpp"


class PhoneBook
{
	Contact contacts[8];
	int contactCount;
	int firstContact;
	void SeeContact(int index);

	void PrintTable(void);
	std::string NewContactInfo(std::string info);
	std::string TableFormat(const std::string& str);

public:
	PhoneBook(void);
	~PhoneBook(void);
	void Intro(void);
	void NewContact(void);
	void SeePhoneBook(void);
};

#endif