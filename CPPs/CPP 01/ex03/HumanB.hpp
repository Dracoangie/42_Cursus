/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:50:36 by angnavar          #+#    #+#             */
/*   Updated: 2025/04/22 18:21:17 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP

# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
	std::string _name;
	Weapon *_weapon;

public:
	HumanB(std::string name);
	~HumanB(void);

	void setWeapon(Weapon *weapon);
	void attack(void);
};

#endif