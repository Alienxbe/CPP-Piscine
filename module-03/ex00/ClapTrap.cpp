/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 05:23:04 by marykman          #+#    #+#             */
/*   Updated: 2025/11/05 06:02:22 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : 
	_name(name), 
	_hp(10), 
	_energy(10), 
	_attack(0)
{
	
}

ClapTrap::ClapTrap(ClapTrap const &other) :
	_name(other._name),
	_hp(other._hp),
	_energy(other._energy),
	_attack(other._attack)
{
	
}

ClapTrap::~ClapTrap()
{
	
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hp = rhs._hp;
		this->_energy = rhs._energy;
		this->_attack = rhs._attack;
	}
	return (*this);
}

void ClapTrap::attack(std::string const &target)
{
	if (this->_energy <= 0 || this->_hp <= 0)
		return ;
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attack << " points of damage!" << std::endl;
	this->_energy--;
}
