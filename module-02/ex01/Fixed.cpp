/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 02:03:47 by marykman          #+#    #+#             */
/*   Updated: 2025/11/05 03:19:53 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

const int	Fixed::_fractional_bit = 8;

// Construcors

Fixed::Fixed(void) : _n(0)
{
	std::cout << "Default constructor called" << std::endl;	
}

Fixed::Fixed(int const n)
{
	std::cout << "Int constructor called" << std::endl;
	this->_n = n << this->_fractional_bit;
}

Fixed::Fixed(float const n)
{
	std::cout << "Float constructor called" << std::endl;
	this->_n = (int)roundf(n * (1 << this->_fractional_bit));
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructeur called" << std::endl;
	*this = src;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// Operator overload

Fixed	&Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_n = rhs.getRawBits();
	return (*this);
}

// Methods

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_n);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits called" << std::endl;
	this->_n = raw;
}

int		Fixed::toInt(void) const
{
	return (this->_n >> this->_fractional_bit);
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_n / (1 << this->_fractional_bit));
}

// Functions

std::ostream &operator<<(std::ostream &o, Fixed const &rhs)
{
	o << rhs.toFloat();
	return (o);
}
