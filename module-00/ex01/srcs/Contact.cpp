/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:37:41 by marykman          #+#    #+#             */
/*   Updated: 2025/11/05 18:43:09 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "utils.hpp"
#include "Contact.hpp"

Contact::Contact(void)
{

}

Contact::~Contact()
{

}

/*
** Display the Contact informations
** 
*/
void	Contact::display_line(unsigned int index)
{
	std::cout << "|";
	std::cout << std::setw(10) << index << "|";
	std::cout << std::setw(10) << truncate(this->first_name, 10) << "|";
	std::cout << std::setw(10) << truncate(this->last_name, 10) << "|";
	std::cout << std::setw(10) << truncate(this->nickname, 10) << "|" << std::endl;
}

void	Contact::display_tab(void)
{
	std::cout << "\t> First name     : " << this->first_name << std::endl;
	std::cout << "\t> Last name      : " << this->last_name << std::endl;
	std::cout << "\t> Nickname       : " << this->nickname << std::endl;
	std::cout << "\t> Phone number   : " << this->phone << std::endl;
	std::cout << "\t> Darkest secret : " << this->darkest_secret << std::endl;
}

bool	Contact::setFields(void)
{
	std::string	values[5];
	std::string	names[5] = {
		"First name",
		"Last name",
		"Nickname",
		"Phone number",
		"Darkest secret"
	};

	for (size_t i = 0; i < 5; i++)
	{
		std::cout << std::left;
		std::cout << "\t" << std::setw(15) << names[i] << " : ";
		std::cout << std::right;
		if (!std::getline(std::cin, values[i]))
			return (false);
		if (values[i] == "")
		{
			std::cout << "\tA contact's field cannot be empty.\n" << std::endl;
			return (false);
		}
	}

	this->first_name = values[0];
	this->last_name = values[1];
	this->nickname = values[2];
	this->phone = values[3];
	this->darkest_secret = values[4];
	std::cout << "Contact added!" << std::endl << std::endl;
	return (true);
}
