/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 11:22:43 by angnavar          #+#    #+#             */
/*   Updated: 2026/05/19 11:48:00 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cerrno>
#include <climits>
#include <cfloat>
#include <cmath>
#include <iomanip>

class ScalarConverter
{
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& other);
	~ScalarConverter();

	static std::string convertToChar(const std::string& literal);
	static std::string convertToInt(const std::string& literal);
	static std::string convertToFloat(const std::string& literal);
	static std::string convertToDouble(const std::string& literal);

public:
	static void convert(const std::string& literal);
};

#endif