/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:55:15 by angnavar          #+#    #+#             */
/*   Updated: 2025/04/21 20:12:53 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP

# define ZOMBIE_HPP

# include <iostream>
# include <string>

class	Zombie
{

	std::string	_name;

public:

	Zombie(void);
	Zombie(std::string name);
	~Zombie(void);

	void Announce(void);
	void SetName(std::string name);
	
};

#endif