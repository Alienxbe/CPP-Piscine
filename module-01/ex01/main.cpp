/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 06:06:00 by marykman          #+#    #+#             */
/*   Updated: 2025/11/04 06:25:16 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	int		size;
	Zombie	*horde;

	size = 5;
	horde = zombieHorde(size, "Bob");
	if (!horde)
		return (1);
	for (int i = 0; i < size; i++)
		horde[i].announce();
	delete [] horde;
	return (0);
}

