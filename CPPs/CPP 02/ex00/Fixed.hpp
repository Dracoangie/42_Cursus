/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:31:48 by angnavar          #+#    #+#             */
/*   Updated: 2025/05/20 13:50:24 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FIXED_HPP_

# define _FIXED_HPP_

# include <iostream>

class Fixed
{
	int					value;
	
public:
	Fixed();
	Fixed(const Fixed &src);
	~Fixed();

	Fixed&	operator=(const Fixed &cpy);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif