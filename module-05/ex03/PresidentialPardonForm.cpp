/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:21:14 by marykman          #+#    #+#             */
/*   Updated: 2025/11/17 20:40:45 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

////// Constructors //////

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) :
	AForm("PresidentialPardon", 25, 5),
	_target(target)
{

}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other) :
	AForm(other),
	_target(other._target)
{
	
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	
}

////// Methods //////

void PresidentialPardonForm::applyForm(void) const
{
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
