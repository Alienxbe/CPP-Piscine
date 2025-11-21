/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:10:38 by marykman          #+#    #+#             */
/*   Updated: 2025/11/17 20:34:19 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include "RobotomyRequestForm.hpp"

////// Constructors //////

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) :
	AForm("RobotomyRequest", 75, 45),
	_target(target)
{
	std::srand(std::time(0));
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) :
	AForm(other),
	_target(other._target)
{
	std::srand(std::time(0));
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	
}

////// Methods //////

void RobotomyRequestForm::applyForm(void) const
{
	std::cout << "* Some drilling noises *" << std::endl;

	if (std::rand() % 2)
		std::cout << this->_target << " has been robotomizes with succes !" << std::endl;
	else
		std::cout << "Robotomy failed for " << this->_target << ".... :(" << std::endl;
}
