/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:50:26 by angnavar          #+#    #+#             */
/*   Updated: 2025/04/22 13:01:25 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP

# define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon
{
	std::string _type;

public:
	Weapon(void);
	Weapon(std::string type);
	~Weapon(void);

	std::string getType(void);
	void setType(std::string type);
};

#endif