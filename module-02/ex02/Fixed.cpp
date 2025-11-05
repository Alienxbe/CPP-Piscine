/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 02:03:47 by marykman          #+#    #+#             */
/*   Updated: 2025/11/05 04:54:59 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

const int	Fixed::_fractional_bit = 8;

// Construcors

Fixed::Fixed(void) : _n(0)
{

}

Fixed::Fixed(int const n)
{
	this->_n = n << this->_fractional_bit;
}

Fixed::Fixed(float const n)
{
	this->_n = (int)roundf(n * (1 << this->_fractional_bit));
}

Fixed::Fixed(Fixed const &src)
{
	*this = src;
}

Fixed::~Fixed()
{

}

// Methods

int		Fixed::getRawBits(void) const
{
	return (this->_n);
}

void	Fixed::setRawBits(int const raw)
{
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

// Static methods

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

Fixed const	&Fixed::min(Fixed const &a, Fixed const &b)
{
	return (a < b ? a : b);
}

Fixed const	&Fixed::max(Fixed const &a, Fixed const &b)
{
	return (a > b ? a : b);
}

// Functions

std::ostream &operator<<(std::ostream &o, Fixed const &rhs)
{
	o << rhs.toFloat();
	return (o);
}
