/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:10:19 by angnavar          #+#    #+#             */
/*   Updated: 2025/04/10 10:33:50 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"


ContactInfo Contact::GetContactEnum()
{
	return(contactEnum);
}

void Contact::SetContact(ContactInfo contactEnum)
{
	this->contactEnum  = contactEnum;
}

Contact::Contact(){};
Contact::~Contact(){};