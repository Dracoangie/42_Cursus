/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:23:24 by angnavar          #+#    #+#             */
/*   Updated: 2025/04/28 15:28:10 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HARL_HPP

# define HARL_HPP

# include <iostream>
# include <string>
# include <unistd.h>

class Harl
{

	void debug( void );
	void info( void );
	void warning( void );
	void error( void );

public:

	Harl(void);
	~Harl(void);
	
	void complain( std::string level );
	void complainFrom( std::string level );
};

#endif