/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:51:36 by marykman          #+#    #+#             */
/*   Updated: 2025/11/09 16:29:38 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	{	// Classic Animal tests
		std::cout << "[ ANIMAL TESTS ]" << std::endl;
		std::cout << "--- Constructor calls ---" << std::endl; 
		const Animal	*meta = new Animal();
		const Animal	*dog = new Dog();
		const Animal	*cat = new Cat();
	
		std::cout << std::endl << "--- calls ---" << std::endl;
		std::cout << dog->getType() << std::endl;
		std::cout << cat->getType() << std::endl;

		meta->makeSound();
		dog->makeSound();
		cat->makeSound();
	
		std::cout << std::endl << "--- Destructor calls ---" << std::endl;
		delete cat;
		delete dog;
		delete meta;
	}

	{	// Wrong animal tests
		std::cout << std::endl << "[ WRONG ANIMAL TESTS ]" << std::endl;
		std::cout << "--- Constructor calls ---" << std::endl; 
		const WrongAnimal	*meta = new WrongAnimal();
		const WrongAnimal	*cat = new WrongCat();
		const WrongCat		*cat2 = new WrongCat();

		std::cout << std::endl << "--- calls ---" << std::endl;
		std::cout << cat->getType() << std::endl;

		meta->makeSound();
		cat->makeSound();	// Will output "WrongAnimal sound" instead of cat Sound
		cat2->makeSound();	// Will output correct sound
		
		std::cout << std::endl << "--- Destructor calls ---" << std::endl;
		delete meta;
		delete cat;
	}
	return (0);
}

