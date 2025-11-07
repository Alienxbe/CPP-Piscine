/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 07:41:58 by marykman          #+#    #+#             */
/*   Updated: 2025/11/07 09:07:02 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name),
	_guarGateMode(false)
{
	this->_hp = 100;
	this->_energy = 50;
	this->_attack = 20;

	std::cout << "ScavTrap name constructor called (" << this->_name << ")" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &other) : ClapTrap(other),
	_guarGateMode(other._guarGateMode)
{
	std::cout << "ScavTrap copy constructor called (" << this->_name << ")" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called (" << this->_name << ")" << std::endl;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &rhs)
{
	if (this != &rhs)
	{
		ClapTrap::operator=(rhs);
		this->_guarGateMode = rhs._guarGateMode;
	}
	return (*this);
}

///// Methods /////

void	ScavTrap::attack(std::string const &target)
{
	std::cout << "[ ATTACK ]" << std::endl;

	if (this->_hp > 0 && this->_energy > 0)
	{
		this->_energy--;
		std::cout << "ScavTrap " << this->_name << " attacks " << target
			<< ", causing " << this->_attack << " points of damage!" << std::endl;
		std::cout << ">> " << this->_energy << " energy left" << std::endl;
	}
	else if (this->_hp <= 0)
		std::cout << "ScavTrap " << this->_name << " is dead" << std::endl;
	else if (this->_energy <= 0)
		std::cout << "ScavTrap " << this->_name << " has no more energy left" << std::endl;

	std::cout << std::endl;
}

void ScavTrap::guardGate(void)
{
	std::cout << "[ MODE ]" << std::endl;
	
	if (this->_hp > 0)
	{
		if (!this->_guarGateMode)
			std::cout << "ScavTrap " << this->_name << " is now in gate keeper mode" << std::endl;
		else
			std::cout << "ScavTrap " << this->_name << " is now in normal mode" << std::endl;
		this->_guarGateMode = !this->_guarGateMode;
	}
	else
		std::cout << "ScavTrap " << this->_name << " is dead" << std::endl;
	

	std::cout << std::endl;
}
