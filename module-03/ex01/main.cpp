/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 05:16:44 by marykman          #+#    #+#             */
/*   Updated: 2025/11/07 15:09:35 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "ScavTrap.hpp"

int main(void)
{
	std::cout << "--- Constructor calls ---" << std::endl;
	
	ScavTrap	st1("Boby");
	ScavTrap	st2("Dylan");
	ClapTrap	ct1("Tester");

	std::cout << std::endl << "--- Actions ---" << std::endl;

	// Changing guard mode into death
	st1.guardGate();
	st1.guardGate();
	st1.takeDamage(200);
	st1.guardGate();

	// Testing the overwritten attack method
	st2.attack("Boby");
	ct1.attack("Boby");

	std::cout << std::endl << "--- Destructor calls ---" << std::endl;
	return 0;
}

