/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:34:11 by marykman          #+#    #+#             */
/*   Updated: 2025/11/09 17:28:31 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog"), _brain(new Brain)
{
	std::cout << "Dog default construcor called" << std::endl;
}

Dog::Dog(Dog const &other) : Animal(other), _brain(new Brain(*other._brain))
{
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->_brain;
}

Dog &Dog::operator=(Dog const &rhs)
{
	std::cout << "Dog assignement operator called" << std::endl;
	if (this != &rhs)
	{
		Animal::operator=(rhs);
		*this->_brain = *rhs._brain;
	}
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << "Wouaf wouaf" << std::endl;
}

std::string const &Dog::getIdea(size_t index) const
{
	return (this->_brain->getIdea(index));
}

void Dog::setIdea(size_t index, std::string const &idea)
{
	this->_brain->setIdea(index, idea);
}
