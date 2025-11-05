/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 02:16:25 by marykman          #+#    #+#             */
/*   Updated: 2025/11/05 05:08:50 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main(void)
{
	{
		std::cout << "--- Subject testing ---" << std::endl;

		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;
		std::cout << std::endl;

	}

	{
		std::cout << "--- Additional testing ---" << std::endl;

		// Comparaisons
		Fixed	a, b;

		a = Fixed(15.4f);
		b = Fixed(32.1f);

		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
		std::cout << "a < b: " << (a < b) << std::endl;
		std::cout << "a > b: " << (a > b) << std::endl;
		std::cout << "a == b: " << (a == b) << std::endl;
		std::cout << "a != b: " << (a != b) << std::endl;
		std::cout << std::endl;

		// arithmetic

		a = Fixed(15.4f);
		b = Fixed(32.1f);

		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
		std::cout << "a + b = " << a + b << std::endl;

	}

	return (0);
}
