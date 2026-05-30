/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 17:10:18 by marykman          #+#    #+#             */
/*   Updated: 2026/05/30 05:56:42 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <stdexcept>

////// CONSTRUCTORS //////

BitcoinExchange::BitcoinExchange(void)
{
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other) :
	_database(other._database)
{
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
	if (this != &rhs)
	{
		this->_database = rhs._database;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

////// DATABASE //////

static bool	isValidDate(std::string const &date)
{
	int		year;
	int		month;
	int		day;
	char	sep1;
	char	sep2;
	int		daysInMonth[12];

	/*
		Expected format:
		YYYY-MM-DD
	*/

	if (date.length() != 10)
		return (false);

	std::istringstream iss(date);
	iss >> year >> sep1 >> month >> sep2 >> day;

	if (iss.fail())
		return (false);
	if (!iss.eof())
		return (false);
	if (sep1 != '-' || sep2 != '-')
		return (false);
	if (month < 1 || month > 12)
		return (false);
	
	/*
		Month's days check
	*/

	daysInMonth[0] = 31;
	daysInMonth[1] = 28;
	daysInMonth[2] = 31;
	daysInMonth[3] = 30;
	daysInMonth[4] = 31;
	daysInMonth[5] = 30;
	daysInMonth[6] = 31;
	daysInMonth[7] = 31;
	daysInMonth[8] = 30;
	daysInMonth[9] = 31;
	daysInMonth[10] = 30;
	daysInMonth[11] = 31;

	if ((year % 4 == 0 && year % 100 != 0)
		|| (year % 400 == 0))
	{
		daysInMonth[1] = 29;
	}

	if (day < 1 || day > daysInMonth[month - 1])
		return (false);

	return (true);
}

static bool	isValidValue(std::string const &value)
{
	char	*end;
	double	number;

	number = std::strtod(value.c_str(), &end);

	if (*end != '\0')
		return (false);
	if (number < 0.0)
		return (false);

	return (true);
}

void BitcoinExchange::loadDatabase(char const *filename)
{
	std::ifstream	file(filename);
	std::string		line;
	bool			firstLine;

	if (!file.is_open())
		throw std::runtime_error("Could not open database file");

	firstLine = true;
	while (std::getline(file, line))
	{
		std::string			date;
		std::string			value;
		std::stringstream	ss;
		float				rate;

		if (firstLine == true)
		{
			firstLine = false;
			if (line != "date,exchange_rate")
				throw std::runtime_error("Invalid database header");
			continue;
		}

		/*
			Empty line protection
		*/

		if (line.empty())
			throw std::runtime_error("Empty line in database");

		/*
			Split using ','
		*/

		ss.str(line);

		if (!std::getline(ss, date, ','))
			throw std::runtime_error("Missing date in database");

		if (!std::getline(ss, value))
			throw std::runtime_error("Missing value in database");

		/*
			Ensure no extra commas
		*/

		if (value.find(',') != std::string::npos)
			throw std::runtime_error("Too many fields in database");

		/*
			Validate date format
		*/

		if (!isValidDate(date))
			throw std::runtime_error("Invalid date in database: " + date);

		if (!isValidValue(value))
			throw std::runtime_error("Invalid exchange rate in database: " + value);

		rate = static_cast<float>(std::strtod(value.c_str(), NULL));

		_database[date] = rate;
	}

	if (_database.empty())
		throw std::runtime_error("Database is empty");
}

////// HEXCHANGE RATE //////

float BitcoinExchange::getExchangeRate(std::string const &date) const
{
	std::map<std::string, float>::const_iterator	it;

	it = _database.lower_bound(date);

	if (it != _database.end() && it->first == date)
		return (it->second);

	if (it == _database.begin())
		throw std::runtime_error("no exchange rate available before this date");

	--it;

	return (it->second);
}

void	BitcoinExchange::processInputFile(char const *filename)
{
	std::ifstream	file(filename);
	std::string		line;
	bool			firstLine;

	if (!file.is_open())
		throw std::runtime_error("could not open input file");

	firstLine = true;

	while (std::getline(file, line))
	{
		std::string			date;
		std::string			valueStr;
		std::size_t			separatorPos;
		double				value;

		if (firstLine)
		{
			firstLine = false;
			if (line != "date | value")
				throw std::runtime_error("invalid input file header");
			continue;
		}
		
		if (line[0] == '#')
			std::cout << std::endl << line << std::endl;

		if (line.empty() || line[0] == '#')
			continue;

		try
		{
			separatorPos = line.find(" | ");

			if (separatorPos == std::string::npos)
				throw std::runtime_error("bad input => " + line);

			date = line.substr(0, separatorPos);
			valueStr = line.substr(separatorPos + 3);

			if (!isValidDate(date))
				throw std::runtime_error("bad input => " + date);

			if (!isValidValue(valueStr))
				throw std::runtime_error("bad input => " + valueStr);

			value = std::strtod(valueStr.c_str(), NULL);

			if (value > 1000)
				throw std::runtime_error("too large a number.");

			std::cout
				<< date
				<< " => "
				<< value
				<< " = "
				<< value * getExchangeRate(date)
				<< std::endl;
		}
		catch (std::exception const &e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
}

////// GETTER //////

std::map<std::string, float> const &BitcoinExchange::getDatabase(void) const
{
	return (_database);
}

////// IOSTREAM //////

std::ostream &operator<<(std::ostream &o, BitcoinExchange const &rhs)
{
	std::map<std::string, float> const &			db = rhs.getDatabase();
	std::map<std::string, float>::const_iterator	it;

	for (it = db.begin(); it != db.end(); ++it)
	{
		o << it->first << " => " << it->second << std::endl;
	}

	return (o);
}
