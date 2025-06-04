/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:31:55 by angnavar          #+#    #+#             */
/*   Updated: 2025/05/20 13:54:10 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP

# define CLAPTRAP_HPP

# include <iostream>
# include <string>
# include <unistd.h>
# include <sstream>

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define CYAN    "\033[36m"
#define YELLOW  "\033[33m"
#define MAGENTA "\033[35m"

class ClapTrap
{
    std::string name;
    int hitPoints;
    int energyPoints;
    int attackDamage;

public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &src);
	~ClapTrap();

	ClapTrap&	operator=(const ClapTrap &cpy);

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    static void typeWrite(const std::string &text, int delayMicroseconds = 30000);
};

#endif