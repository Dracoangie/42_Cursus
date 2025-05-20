/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:05:08 by angnavar          #+#    #+#             */
/*   Updated: 2025/04/10 12:06:40 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP

# define CONTACT_HPP

# include <iostream>
# include <string>

struct ContactInfo
{
	std::string firstName;
	std::string lastName;
	std::string phoneNumber;
	std::string darkestSecret;
};

class	Contact
{
	ContactInfo contactEnum;
	
public:
	Contact(void);
	~Contact(void);

	ContactInfo GetContactEnum(void);
	void SetContact(ContactInfo contactEnum);
};

#endif