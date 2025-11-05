/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 19:39:42 by marykman          #+#    #+#             */
/*   Updated: 2025/11/05 00:28:44 by marykman         ###   ########.fr       */
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

void Harl::complain(std::string level)
{
	t_fmsg		fct[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	names[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
		if (level == names[i])
			(this->*(fct[i]))();
}
