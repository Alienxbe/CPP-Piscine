/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:04:37 by marykman          #+#    #+#             */
/*   Updated: 2026/03/24 07:20:39 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

void tester(void)
{
	std::cout << "===== TESTING Array TEMPLATE =====\n\n";

	// 1️⃣ Default constructor
	Array<int> empty;
	std::cout << "Default constructor, size: " << empty.size() << "\n";

	// 2️⃣ Constructor with size
	Array<int> numbers(5); // should be zero-initialized
	std::cout << "Constructor with size 5, elements: ";
	for (unsigned int i = 0; i < numbers.size(); ++i)
		std::cout << numbers[i] << " ";
	std::cout << "\n";

	// Modify elements
	for (unsigned int i = 0; i < numbers.size(); ++i)
		numbers[i] = i * 10;

	std::cout << "Modified elements: ";
	for (unsigned int i = 0; i < numbers.size(); ++i)
		std::cout << numbers[i] << " ";
	std::cout << "\n";

	// 3️⃣ Copy constructor
	Array<int> copyNumbers(numbers);
	copyNumbers[0] = 999; // should not affect original
	std::cout << "Original after copy modification: ";
	for (unsigned int i = 0; i < numbers.size(); ++i)
		std::cout << numbers[i] << " ";
	std::cout << "\n";

	std::cout << "Copy elements: ";
	for (unsigned int i = 0; i < copyNumbers.size(); ++i)
		std::cout << copyNumbers[i] << " ";
	std::cout << "\n";

	// 4️⃣ Assignment operator
	Array<int> assigned;
	assigned = numbers;
	assigned[1] = 555; // should not affect numbers
	std::cout << "Original after assignment modification: ";
	for (unsigned int i = 0; i < numbers.size(); ++i)
		std::cout << numbers[i] << " ";
	std::cout << "\n";

	std::cout << "Assigned elements: ";
	for (unsigned int i = 0; i < assigned.size(); ++i)
		std::cout << assigned[i] << " ";
	std::cout << "\n";

	// 5️⃣ Const array access
	const Array<int> constArr(numbers);
	std::cout << "Accessing const array: ";
	for (unsigned int i = 0; i < constArr.size(); ++i)
		std::cout << constArr[i] << " ";
	std::cout << "\n";

	// 6️⃣ Bounds checking
	try {
		std::cout << "Access out of bounds: ";
		std::cout << numbers[10]; // should throw
	} catch (std::out_of_range &e) {
		std::cout << "Caught exception: " << e.what() << "\n";
	}

	// 7️⃣ Test with another type
	Array<std::string> words(3);
	words[0] = "Hello";
	words[1] = "Array";
	words[2] = "Template";

	std::cout << "String array: ";
	for (unsigned int i = 0; i < words.size(); ++i)
		std::cout << words[i] << " ";
	std::cout << "\n";

	// 8️⃣ Empty array assignment
	Array<int> empty2;
	empty2 = numbers;
	std::cout << "Empty array after assignment, size: " << empty2.size() << "\n";

	std::cout << "\n===== ALL TESTS PASSED (if no exceptions) =====\n";
}

void testerv2(void)
{
	std::cout << "===== ARRAY TEMPLATE TESTER =====\n\n";

	// 1️⃣ Default constructor
	std::cout << "[1] Default constructor\n";
	Array<int> empty;
	std::cout << "Size: " << empty.size() << "\n\n";

	// 2️⃣ Constructor with size
	std::cout << "[2] Constructor with size 5\n";
	Array<int> numbers(5); // zero-initialized
	std::cout << "Initial elements: ";
	for (unsigned int i = 0; i < numbers.size(); ++i)
		std::cout << numbers[i] << " ";
	std::cout << "\n";

	// Modify elements
	for (unsigned int i = 0; i < numbers.size(); ++i)
		numbers[i] = i * 10;

	std::cout << "Modified elements: ";
	for (unsigned int i = 0; i < numbers.size(); ++i)
		std::cout << numbers[i] << " ";
	std::cout << "\n\n";

	// 3️⃣ Copy constructor
	std::cout << "[3] Copy constructor\n";
	Array<int> copyNumbers(numbers);
	copyNumbers[0] = 999; // should not affect original
	std::cout << "Original: ";
	for (unsigned int i = 0; i < numbers.size(); ++i)
		std::cout << numbers[i] << " ";
	std::cout << "\nCopy:     ";
	for (unsigned int i = 0; i < copyNumbers.size(); ++i)
		std::cout << copyNumbers[i] << " ";
	std::cout << "\n\n";

	// 4️⃣ Assignment operator
	std::cout << "[4] Assignment operator\n";
	Array<int> assigned;
	assigned = numbers;
	assigned[1] = 555; // should not affect numbers
	std::cout << "Original: ";
	for (unsigned int i = 0; i < numbers.size(); ++i)
		std::cout << numbers[i] << " ";
	std::cout << "\nAssigned: ";
	for (unsigned int i = 0; i < assigned.size(); ++i)
		std::cout << assigned[i] << " ";
	std::cout << "\n\n";

	// 5️⃣ Const array access
	std::cout << "[5] Const array access\n";
	const Array<int> constArr(numbers);
	std::cout << "Elements: ";
	for (unsigned int i = 0; i < constArr.size(); ++i)
		std::cout << constArr[i] << " ";
	std::cout << "\n\n";

	// 6️⃣ Bounds checking
	std::cout << "[6] Bounds checking\n";
	try {
		std::cout << "Accessing index 10: ";
		std::cout << numbers[10] << "\n"; // should throw
	} catch (const std::exception &e) {
		std::cout << "Caught exception: " << e.what() << "\n";
	}
	std::cout << "\n";

	// 7️⃣ Test with another type (string)
	std::cout << "[7] Array of strings\n";
	Array<std::string> words(3);
	words[0] = "Hello";
	words[1] = "Array";
	words[2] = "Template";
	for (unsigned int i = 0; i < words.size(); ++i)
		std::cout << words[i] << " ";
	std::cout << "\n\n";

	// 8️⃣ Empty array assignment
	std::cout << "[8] Empty array assignment\n";
	Array<int> empty2;
	empty2 = numbers;
	std::cout << "Size after assignment: " << empty2.size() << "\n";
	std::cout << "Elements: ";
	for (unsigned int i = 0; i < empty2.size(); ++i)
		std::cout << empty2[i] << " ";
	std::cout << "\n\n";

	std::cout << "===== ALL TESTS COMPLETED =====\n";
}

int	main(void)
{
	testerv2();
	return (0);
}