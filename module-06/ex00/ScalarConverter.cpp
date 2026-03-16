/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 18:16:55 by marykman          #+#    #+#             */
/*   Updated: 2026/03/16 19:29:24 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <cstdlib>
#include <sstream>
#include "ScalarConverter.hpp"

/*

1) Find origin type
	if (size=1 AND isPrint)
		=> Char
	if (hasOne '.' OR StartWith(+inf, -inf, nan))
		if (EndWith 'f')
			=> Float
		else
			=> double
	if (isNumber)
		=> Int
	else
		=> ERROR


2) Call convertFromType function
	- Each convertFromType function convert to all 4 types: char, int, float, double

*/

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

t_type	getType(std::string const &literal)
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

void ScalarConverter::convert(std::string const &literal)
{
	t_type	type;

	type = getType(literal);
	std::cout << type << std::endl;
}