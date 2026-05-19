/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 11:23:09 by angnavar          #+#    #+#             */
/*   Updated: 2026/05/19 11:58:27 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::~ScalarConverter()
{
}

static bool isCharLiteral(const std::string& s)
{
    return s.length() == 1 && !std::isdigit(s[0]);
}

static std::string normalizeLiteral(std::string s)
{
    if (s == "nanf")
        return "nan";
    else if (s == "+inff")
        return "+inf";
    else if (s == "-inff")
        return "-inf";
	else if (s == "-inf")
		return "-inf";
	else if (s == "+inf")
		return "+inf";
    else if (s.length() > 1 && s[s.length() - 1] == 'f')
        return s.substr(0, s.length() - 1);
    return s;
}

static bool parseDouble(const std::string& literal, double& value)
{
    if (isCharLiteral(literal))
    {
        value = static_cast<double>(literal[0]);
        return true;
    }

    std::string s = normalizeLiteral(literal);

    char* endptr;
    errno = 0;
    value = std::strtod(s.c_str(), &endptr);

    if (*s.c_str() == '\0' || *endptr != '\0')
        return false;
    if (errno == ERANGE)
        return false;

    return true;
}

std::string ScalarConverter::convertToChar(const std::string& literal)
{
    double value;

    if (!parseDouble(literal, value))
        return "impossible";

    if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127)
        return "impossible";

    char c = static_cast<char>(value);

    if (!std::isprint(c))
        return "Non displayable";

    std::string result = "'";
    result += c;
    result += "'";
    return result;
}

std::string ScalarConverter::convertToInt(const std::string& literal)
{
    double value;

    if (!parseDouble(literal, value))
        return "impossible";

    if (std::isnan(value) || std::isinf(value)
        || value < INT_MIN || value > INT_MAX)
        return "impossible";

    std::ostringstream oss;
    oss << static_cast<int>(value);

    return oss.str();
}

std::string ScalarConverter::convertToFloat(const std::string& literal)
{
    double value;

    if (!parseDouble(literal, value))
        return "impossible";

    if (!std::isnan(value) && !std::isinf(value)
        && (value > FLT_MAX || value < -FLT_MAX))
        return "impossible";

    std::ostringstream oss;

    oss << static_cast<float>(value);

    if (!std::isnan(value) && !std::isinf(value)
        && value == static_cast<int>(value))
        oss << ".0";

    oss << "f";

    return oss.str();
}

std::string ScalarConverter::convertToDouble(const std::string& literal)
{
    double value;

    if (!parseDouble(literal, value))
        return "impossible";

    std::ostringstream oss;

    oss << value;

    if (!std::isnan(value) && !std::isinf(value)
        && value == static_cast<int>(value))
        oss << ".0";

    return oss.str();
}

void ScalarConverter::convert(const std::string& literal)
{
    std::cout << "char: " << convertToChar(literal) << std::endl;
    std::cout << "int: " << convertToInt(literal) << std::endl;
    std::cout << "float: " << convertToFloat(literal) << std::endl;
    std::cout << "double: " << convertToDouble(literal) << std::endl;
}