/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 16:34:55 by marykman          #+#    #+#             */
/*   Updated: 2025/11/09 16:59:31 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(Brain const &other) : _ideas(other._ideas)
{
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain	&Brain::operator=(Brain const &rhs)
{
	std::cout << "Brain assignement operator called" << std::endl;
	if (this != &rhs)
	{
		for (size_t i = 0; i < 100; i++)
			this->_ideas[i] = rhs._ideas[i];
	}
	return (*this);
}

std::string const &Brain::getIdea(size_t index) const
{
	if (index >= 100)
	{
		std::cout << "Idea range is too big" << std::endl;
		return (_ideas[0]);
	}
	return (_ideas[index]);
}

void Brain::setIdea(size_t index, std::string const &idea)
{
	if (index >= 100)
	{
		std::cout << "Idea range is too big" << std::endl;
		return ;
	}
	_ideas[index] = idea;
}
