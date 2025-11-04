/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 06:06:00 by marykman          #+#    #+#             */
/*   Updated: 2025/11/04 06:11:29 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	// Heap Zombie
	Zombie	*zombie;

	zombie = newZombie("Bob");
	zombie->announce();
	delete zombie;

	// stack Zombie
	randomChump("Ronald");
	return 0;
}

