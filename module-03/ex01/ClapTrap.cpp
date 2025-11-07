/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 05:23:04 by marykman          #+#    #+#             */
/*   Updated: 2025/11/07 07:17:09 by marykman         ###   ########.fr       */
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
	std::cout << "ClapTrap name constructor called (" << this->_name << ")" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &other) :
	_name(other._name),
	_hp(other._hp),
	_energy(other._energy),
	_attack(other._attack)
{
	std::cout << "ClapTrap copy constructor called (" << this->_name << ")" << std::endl;

}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called (" << this->_name << ")" << std::endl;
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
	std::cout << "ClapTrap assigned operator called (" << this->_name << ")" << std::endl;
	return (*this);
}

void ClapTrap::attack(std::string const &target)
{
	std::cout << "[ ATTACK ]" << std::endl;

	if (this->_hp > 0 && this->_energy > 0)
	{
		this->_energy--;
		std::cout << "ClapTrap " << this->_name << " attacks " << target
			<< ", causing " << this->_attack << " points of damage!" << std::endl;
		std::cout << ">> " << this->_energy << " energy left" << std::endl;
	}
	else if (this->_hp <= 0)
		std::cout << "ClapTrap " << this->_name << " is dead" << std::endl;
	else if (this->_energy <= 0)
		std::cout << "ClapTrap " << this->_name << " has no more energy left" << std::endl;

	std::cout << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "[ DAMAGE TAKEN ]" << std::endl;

	if (this->_hp <= 0)
		std::cout << "ClapTrap " << this->_name << " is dead" << std::endl;
	else if ((unsigned int)this->_hp < amount)
	{
		this->_hp = 0;
		std::cout << "ClapTrap " << this->_name << " takes " << amount << " damages and dies..." << std::endl;
	}
	else
	{
		this->_hp -= amount;
		std::cout << "ClapTrap " << this->_name << " takes " << amount << " damages (total: " << this->_hp << ")" << std::endl;
	}

	std::cout << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "[ HEALING ]" << std::endl;

	if (this->_hp > 0 && this->_energy > 0)
	{
		this->_energy--;
		this->_hp += amount;

		std::cout << "ClapTrap " << this->_name << " is healed for " << amount << " hp (total: " << this->_hp << ")" << std::endl;
		std::cout << ">> " << this->_energy << " energy left" << std::endl;
	}
	else if (this->_hp <= 0)
		std::cout << "ClapTrap " << this->_name << " is dead" << std::endl;
	else if (this->_energy <= 0)
		std::cout << "ClapTrap " << this->_name << " has no more energy left" << std::endl;

	std::cout << std::endl;
}
