/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 05:16:44 by marykman          #+#    #+#             */
/*   Updated: 2025/11/07 15:04:33 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "ClapTrap.hpp"

int main(void)
{
	std::cout << "--- Constructor calls ---" << std::endl;
	ClapTrap	ct1("Patrick");
	ClapTrap	ct2("r2d2");
	ClapTrap	ct3(ct1);
	ct3 = ClapTrap("c3po");

	std::cout << std::endl << "--- Actions ---" << std::endl;

	// No more energy on attacking
	for (int i = 0; i < 11; i++)
	{
		std::cout << i << ": ";
		ct1.attack("r2d2");
	}

	// No more energy on healing
	ct2.takeDamage(9);
	ct2.attack("Patrick");
	for (int i = 0; i < 11; i++)
	{
		std::cout << i << ": ";
		ct2.beRepaired(1);
	}

	// Die
	ct3.takeDamage(15);
	ct3.beRepaired(10);

	std::cout << std::endl << "--- Destructor calls ---" << std::endl;
	return 0;
}

