/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 02:28:10 by marykman          #+#    #+#             */
/*   Updated: 2026/03/31 14:56:06 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int	main(void)
{
	Data data;
	data.x = 42;
	data.y = 3;

	// Original pointer
	Data* original = &data;

	// Serialize
	uintptr_t raw = Serializer::serialize(original);

	// Deserialize
	Data* result = Serializer::deserialize(raw);

	// Test
	std::cout << "Original pointer:   " << original << std::endl;
	std::cout << "Serialized (raw):   " << raw << std::endl;
	std::cout << "Deserialized ptr:   " << result << std::endl;

	std::cout << "\nSame address? ";
	if (original == result)
		std::cout << "YES ✅\n";
	else
		std::cout << "NO ❌\n";

	// Extra check: data is still accessible
	std::cout << "\nData values:\n";
	std::cout << "x = " << result->x << "\n";
	std::cout << "y = " << result->y << "\n";

	return (0);
}