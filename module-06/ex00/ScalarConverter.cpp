/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 18:16:55 by marykman          #+#    #+#             */
/*   Updated: 2026/03/24 02:34:31 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstdlib>
#include <sstream>
#include <limits>
#include <cmath>
#include "ScalarConverter.hpp"

/// DETECTION ///

template <typename T>
static bool	isNumericType(std::string const &literal)
{
	std::istringstream	ss(literal);
	T					value;

	if (literal == "+inf" || literal == "-inf" || literal == "nan")
		return (true);
	return ((ss >> value) && ss.eof());
}

static bool isFloat(std::string const &literal)
{
	size_t	literal_len;

	literal_len = literal.size();
	if (literal[literal_len - 1] != 'f')
		return (false);
	return (isNumericType<float>(literal.substr(0, literal_len - 1)));
}

static t_type	getType(std::string const &literal)
{
	std::stringstream	ss;

	if (isNumericType<int>(literal))
		return (INT);
	if (isNumericType<double>(literal))
		return (DOUBLE);
	if (isFloat(literal))
		return (FLOAT);
	if (literal.length() == 1 && std::isprint(literal[0]))
		return (CHAR);
	return (ERROR_TYPE);
}

/// PARSING ///

static double	parseToDouble(const std::string& literal)
{
	if (literal == "nan" || literal == "nanf")
		return std::numeric_limits<double>::quiet_NaN();

	if (literal == "+inf" || literal == "+inff")
		return std::numeric_limits<double>::infinity();

	if (literal == "-inf" || literal == "-inff")
		return -std::numeric_limits<double>::infinity();

	// remove 'f' if present
	std::string s = literal;
	if (!s.empty() && s[s.length() - 1] == 'f')
		s = s.substr(0, s.length() - 1);

	std::istringstream iss(s);
	double value = 0;
	iss >> value;

	return value;
}

/// CONVERTION ///

static void	convertFromDouble(double value)
{
	// ---------- CHAR ----------
	if (std::isnan(value) || value < 0 || value > 127)
		std::cout << "char: impossible\n";
	else if (!std::isprint(static_cast<int>(value)))
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: '" << static_cast<char>(value) << "'\n";

	// ---------- INT ----------
	if (std::isnan(value) ||
		value > std::numeric_limits<int>::max() ||
		value < std::numeric_limits<int>::min())
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << static_cast<int>(value) << "\n";

	// ---------- FLOAT ----------
	std::cout << "float: ";

	if (std::isnan(value))
		std::cout << "nanf\n";
	else if (std::isinf(value))
		std::cout << (value < 0 ? "-inff\n" : "+inff\n");
	else
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f\n";

	// ---------- DOUBLE ----------
	std::cout << "double: ";

	if (std::isnan(value))
		std::cout << "nan\n";
	else if (std::isinf(value))
		std::cout << (value < 0 ? "-inf\n" : "+inf\n");
	else
		std::cout << std::fixed << std::setprecision(1) << static_cast<double>(value) << "\n";
}

static void	convertFromChar(char c)
{
	double value = static_cast<double>(c);
	convertFromDouble(value);
}

void ScalarConverter::convert(std::string const &literal)
{
	t_type	type;

	type = getType(literal);
	switch (type)
	{
		case CHAR:
			convertFromChar(literal[0]);
			break;

		case INT:
		case FLOAT:
		case DOUBLE:
		{
			double value = parseToDouble(literal);
			convertFromDouble(value);
			break;
		}
			
		default:
			break;
	}
}