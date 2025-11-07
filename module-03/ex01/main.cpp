/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 05:16:44 by marykman          #+#    #+#             */
/*   Updated: 2025/11/07 08:50:00 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "ScavTrap.hpp"

int main(void)
{
	std::cout << "--- Constructor calls ---" << std::endl;
	
	ScavTrap	st1("Boby");
	ScavTrap	st2("Dylan");

	std::cout << std::endl << "--- Actions ---" << std::endl;
	st1.guardGate();
	st1.guardGate();
	st1.takeDamage(200);
	st1.guardGate();

	st2.attack("Boby");

	std::cout << std::endl << "--- Destructor calls ---" << std::endl;
	return 0;
}

