/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:37:41 by marykman          #+#    #+#             */
/*   Updated: 2025/11/04 04:07:57 by marykman         ###   ########.fr       */
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
void	Contact::display(unsigned int index)
{
	std::cout << "|";
	std::cout << std::setw(10) << index << "|";
	std::cout << std::setw(10) << truncate(this->first_name, 10) << "|";
	std::cout << std::setw(10) << truncate(this->last_name, 10) << "|";
	std::cout << std::setw(10) << truncate(this->nickname, 10) << "|" << std::endl;
}
