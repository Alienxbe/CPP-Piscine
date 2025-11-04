/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:10:48 by marykman          #+#    #+#             */
/*   Updated: 2025/11/04 05:12:08 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "utils.hpp"
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->count = 0;
	this->index = 0;
}

PhoneBook::~PhoneBook(void)
{

}

void	PhoneBook::add_contact()
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
			return ;
	}

	this->_contacts[this->index].first_name = values[0];
	this->_contacts[this->index].last_name = values[1];
	this->_contacts[this->index].nickname = values[2];
	this->_contacts[this->index].phone = values[3];
	this->_contacts[this->index].darkest_secret = values[4];
	std::cout << "Contact added!" << std::endl << std::endl;

	this->index = (this->index + 1) % MAX_CONTACT;
	if (this->count < MAX_CONTACT)
		this->count++;
}

void	PhoneBook::display()
{
	std::cout << std::endl;
	std::cout << "┌-------------------------------------------┐" << std::endl;
	std::cout << "|   Index  |First Name| Last Name| Nickname |" << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;

	for (unsigned int i = 0; i < this->count; i++)
		this->_contacts[i].display(i);
	
	if (!this->count)
		std::cout << "|                   EMPTY                   |" << std::endl;
	
	std::cout << "└-------------------------------------------┘" << std::endl;
}

void	PhoneBook::search()
{
	std::string	value;
	int			index;

	this->display();

	if (!this->count)
	{
		std::cout << std::endl;
		return ;
	}

	std::cout << "\t> Enter the contact index: ";
	if (!std::getline(std::cin, value))
		return ;
	
	index = atoi(value.c_str());
	if (!is_number(value) || !(index >= 0 && (unsigned int)index < this->count) || !value.length())
	{
		std::cout << "\t> Not a valid index... Aborting..." << std::endl << std::endl;
		return ;
	}

	std::cout << "\t> First name     : " << this->_contacts[index].first_name << std::endl;
	std::cout << "\t> Last name      : " << this->_contacts[index].last_name << std::endl;
	std::cout << "\t> Nickname       : " << this->_contacts[index].nickname << std::endl;
	std::cout << "\t> Phone number   : " << this->_contacts[index].phone << std::endl;
	std::cout << "\t> Darkest secret : " << this->_contacts[index].darkest_secret << std::endl;
	std::cout << std::endl;
}