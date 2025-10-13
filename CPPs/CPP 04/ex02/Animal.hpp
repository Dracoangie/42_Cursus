/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:39:18 by angnavar          #+#    #+#             */
/*   Updated: 2025/10/13 19:08:32 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP

# define ANIMAL_HPP

# include <iostream>
# include <string>
# include <unistd.h>
# include <sstream>

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define CYAN    "\033[36m"
#define BLUE    "\033[34m"
#define YELLOW  "\033[33m"
#define PINK    "\033[95m"
#define MAGENTA "\033[35m"

#define BGREEN   "\033[42m"
#define BRED     "\033[41m"
#define BCYAN    "\033[46m"
#define BYELLOW  "\033[43m"
#define BMAGENTA "\033[45m"

class Animal
{
protected:
	std::string type;
public:
	Animal();
	virtual ~Animal();
	Animal(const Animal &other);
	Animal &operator=(const Animal &other);
	virtual void makeSound() const;
	std::string getType() const;
};

#endif