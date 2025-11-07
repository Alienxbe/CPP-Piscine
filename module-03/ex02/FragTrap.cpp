/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 09:01:44 by marykman          #+#    #+#             */
/*   Updated: 2025/11/07 09:15:36 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hp = 100;
	this->_energy = 100;
	this->_attack = 30;

	std::cout << "FragTrap name constructor called (" << this->_name << ")" << std::endl;
}

FragTrap::FragTrap(FragTrap const &other) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called (" << this->_name << ")" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called (" << this->_name << ")" << std::endl;
}

FragTrap	&FragTrap::operator=(FragTrap const &rhs)
{
	if (this != &rhs)
	{
		ClapTrap::operator=(rhs);
	}
	std::cout << "FragTrap assigned operator called (" << this->_name << ")" << std::endl;
	return (*this);
}

///// Methods /////

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name << " asked for a high five !" << std::endl;
}
