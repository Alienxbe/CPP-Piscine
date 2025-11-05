/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:10:48 by marykman          #+#    #+#             */
/*   Updated: 2025/11/05 18:42:46 by marykman         ###   ########.fr       */
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
	if (!this->_contacts[this->index].setFields())
		return ;
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
		this->_contacts[i].display_line(i);
	
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
	this->_contacts[index].display_tab();
	std::cout << std::endl;
}