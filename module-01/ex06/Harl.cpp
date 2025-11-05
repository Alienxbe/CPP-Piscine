/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 19:39:42 by marykman          #+#    #+#             */
/*   Updated: 2025/11/05 00:41:34 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

// Private Methods

void Harl::debug(void)
{
	std::cout << "This is a debug message" << std::endl;
}

void Harl::info(void)
{
	std::cout << "This is an info message" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "This is a warning message" << std::endl;
}

void Harl::error(void)
{
	std::cout << "This is an error message" << std::endl;	
}

// Public Methods

Harl::Harl()
{

}

Harl::~Harl()
{
	
}

static int	get_level_id(std::string level)
{
	std::string	names[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (size_t i = 0; i < 4; i++)
		if (names[i] == level)
			return (i);
	return (-1);
}

void Harl::complain(std::string level)
{
	int	level_id;
	
	level_id = get_level_id(level);
	switch (level_id)
	{
		case 0:
			std::cout << "[ DEBUG ]" << std::endl;
			this->debug();
			std::cout << std::endl;
			// fall through
		
		case 1:
			std::cout << "[ INFO ]" << std::endl;
			this->info();
			std::cout << std::endl;
			// fall through

		case 2:
			std::cout << "[ WARNING ]" << std::endl;
			this->warning();
			std::cout << std::endl;
			// fall through

		case 3:
			std::cout << "[ ERROR ]" << std::endl;
			this->error();
			std::cout << std::endl;
			break ;

		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}
