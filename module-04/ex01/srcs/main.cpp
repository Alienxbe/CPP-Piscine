/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:51:36 by marykman          #+#    #+#             */
/*   Updated: 2025/11/09 17:39:37 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

#define SIZE	10

int main(void)
{
	{
		std::cout << "\t[ STANDARD TESTS ] " << std::endl;
		std::cout << "--- Constructor ---" << std::endl;
		const Animal* j = new Dog();
		const Animal* i = new Cat();
	
		std::cout << std::endl << "--- Destructors ---" << std::endl;
		delete j; // devrait appeler Dog::~Dog() et Brain::~Brain()
		delete i; // devrait appeler Cat::~Cat() et Brain::~Brain()
	}
	{
		std::cout << std::endl << "\t[ STANDARD TESTS ] " << std::endl;
		std::cout << "--- Constructor ---" << std::endl;
		Animal* animals[SIZE];

		for (int i = 0; i < SIZE / 2; ++i)
			animals[i] = new Dog();
		for (int i = SIZE / 2; i < SIZE; ++i)
			animals[i] = new Cat();

		std::cout << std::endl << "--- Destructors ---" << std::endl;
		for (int i = 0; i < SIZE; ++i)
			delete animals[i];
	}
	{
		std::cout << std::endl << "\t[ DEEP COPY ] " << std::endl;
		std::cout << "--- Constructor ---" << std::endl;
		Dog dog;
		dog.setIdea(0, "I want a bone!");
		Dog copy = dog; // test copy constructor

		std::cout << "Original Dog Brain Idea[0]: " << dog.getIdea(0) << std::endl;
		std::cout << "Copied Dog Brain Idea[0]:   " << copy.getIdea(0) << std::endl;

		dog.setIdea(0, "Changed idea!");
		std::cout << "Original Dog Brain Idea[0] (after change): " << dog.getIdea(0) << std::endl;
		std::cout << "Copied Dog Brain Idea[0] (should be unchanged): " << copy.getIdea(0) << std::endl;

		std::cout << std::endl << "--- Destructors ---" << std::endl;
	}
	return (0);
}

