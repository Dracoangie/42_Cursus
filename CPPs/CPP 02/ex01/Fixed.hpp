/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:31:48 by angnavar          #+#    #+#             */
/*   Updated: 2025/05/21 14:27:05 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FIXED_HPP_

# define _FIXED_HPP_

# include <iostream>

class Fixed
{
private:
	int					value;
	static const int	fixed_bits = 8;

public:
	Fixed();
	Fixed(const Fixed &src);
	Fixed(const int int_num);
	Fixed(const float float_num);
	~Fixed();

	Fixed&	operator=(const Fixed &cpy);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	float	toFloat(void) const;
	int		toInt(void) const;
};

#endif