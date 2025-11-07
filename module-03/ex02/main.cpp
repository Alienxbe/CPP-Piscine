/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 05:16:44 by marykman          #+#    #+#             */
/*   Updated: 2025/11/07 09:27:45 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "FragTrap.hpp"

int main(void)
{
	std::cout << "--- Constructor calls ---" << std::endl;
	FragTrap	ft1("Roland");
	FragTrap	ft2("Paul");

	std::cout << std::endl << "--- Actions ---" << std::endl;

	ft1.attack("a bad person");
	ft1.takeDamage(15);
	ft1.beRepaired(20);

	ft1.highFivesGuys();
	ft2.highFivesGuys();
	ft1.highFivesGuys();
	std::cout << std::endl << "--- Destructor calls ---" << std::endl;
	return 0;
}

