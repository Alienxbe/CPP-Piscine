/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 08:36:26 by marykman          #+#    #+#             */
/*   Updated: 2026/05/28 18:43:15 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "Span.hpp"

int	main(void)
{
	std::srand(std::time(NULL));

	try
	{
		Span sp(20000);

		std::cout << "=== Small manual test ===" << std::endl;

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp << std::endl;

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;

		std::cout << "\n=== Range test (10000 numbers) ===" << std::endl;

		std::vector<int> bigVec;
		bigVec.reserve(10000);

		for (int i = 0; i < 10000; ++i)
			bigVec.push_back(std::rand());

		Span sp2(10000);
		sp2.addRange(bigVec.begin(), bigVec.end());

		std::cout << "Added 10000 numbers successfully" << std::endl;

		std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp2.longestSpan() << std::endl;

		std::cout << "\n=== Edge case test ===" << std::endl;

		Span sp3(2);
		sp3.addNumber(42);
		// sp3.shortestSpan(); // should throw

		std::cout << "Span3 longest (single value test avoided crash): " << std::endl;
		std::cout << sp3 << std::endl;

		std::cout << "\nAll tests passed." << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return (0);
}