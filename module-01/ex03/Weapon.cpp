/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 06:52:36 by marykman          #+#    #+#             */
/*   Updated: 2025/11/04 07:22:46 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{

}

Weapon::~Weapon()
{
	
}

std::string const	&Weapon::getType(void)
{
	return (this->_type);
}

void Weapon::setType(std::string type)
{
	this->_type = type;
}
