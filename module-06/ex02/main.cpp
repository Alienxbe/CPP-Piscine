/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 02:28:10 by marykman          #+#    #+#             */
/*   Updated: 2026/03/24 03:28:54 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

static Base	*generate()
{
	switch (std::rand() % 3)
	{
		case 0: return (new A());
		case 1: return (new B());
		case 2: return (new C());
	}
	return (NULL);
}

static void	identify(Base *p)
{
	if(dynamic_cast<A*>(p))
		std::cout << "Class A is identified" << std::endl;
	else if(dynamic_cast<B*>(p))
		std::cout << "Class B is identified" << std::endl;
	else if(dynamic_cast<C*>(p))
		std::cout << "Class C is identified" << std::endl;
	else
		std::cout << "The given pointer is none of the choices" << std::endl;
}

static void	identify(Base &p)
{
	try
	{
		A	&a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "Class A is identified" << std::endl;
		return ;
	} catch (std::exception &e) {}
	try
	{
		B	&b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "Class B is identified" << std::endl;
		return ;
	} catch (std::exception &e) {}
	try
	{
		C	&c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "Class C is identified" << std::endl;
		return ;
	} catch (std::exception &e) {}
	std::cout << "The given pointer is none of the choices" << std::endl;
}

int	main(void)
{
	// Setting random seed depending on time
	std::srand(std::time(NULL));

	Base	*obj;

	obj = generate();

	identify(obj);
	identify(*obj);

	delete obj;
}