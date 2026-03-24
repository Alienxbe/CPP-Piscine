/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 05:46:42 by marykman          #+#    #+#             */
/*   Updated: 2026/03/24 06:34:14 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

// Print function (read-only)
template <typename T>
void print(const T& x)
{
	std::cout << x << " ";
}

// Increment function (modifies elements)
template <typename T>
void increment(T& x)
{
	++x;
}

int main() {
	// ----- INT ARRAY -----
	int arr[] = {1, 2, 3, 4};
	size_t len = sizeof(arr) / sizeof(arr[0]);

	std::cout << "Original: ";
	::iter(arr, len, print<int>);
	std::cout << std::endl;

	::iter(arr, len, increment<int>);

	std::cout << "After increment: ";
	::iter(arr, len, print<int>);
	std::cout << std::endl;


	// ----- STRING ARRAY -----
	std::string strs[] = {"Hello", "World"};
	size_t lenStr = sizeof(strs) / sizeof(strs[0]);

	std::cout << "Strings: ";
	::iter(strs, lenStr, print<std::string>);
	std::cout << std::endl;


	// ----- CONST ARRAY -----
	const int constArr[] = {10, 20, 30};

	std::cout << "Const array: ";
	::iter(constArr, 3, static_cast<void(*)(const int&)>(print));
	std::cout << std::endl;

	return (0);
}
