/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:57:23 by marykman          #+#    #+#             */
/*   Updated: 2025/11/15 00:37:44 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main(void)
{
	{	// Working code
		std::cout << "\t[ WORKING CODE ]" << std::endl;

		Bureaucrat	bob("Bob", 10);
		Bureaucrat	anne("Anne", 4);

		std::cout << bob << std::endl;
		std::cout << anne << std::endl;
		bob.incrementGrade();
		anne.decrementGrade();
		std::cout << bob << std::endl;
		std::cout << anne << std::endl;
	}
	{	// Error catching
		std::cout << std::endl << "\t[ ERROR CATCHING ]" << std::endl;

		try
		{
			Bureaucrat	eddie("Eddie", 150);	// Lowest grade possible

			std::cout << eddie << std::endl;
			eddie.decrementGrade();				// Try lowering it
			std::cout << eddie << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "An error occured :" << std::endl;
			std::cout << e.what() << std::endl;
		}
		// Code will continue here
	}
	return (0);
}
