/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 06:15:31 by marykman          #+#    #+#             */
/*   Updated: 2025/11/04 06:24:41 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
Zombie	*zombieHorde(int n, std::string name)
{
	Zombie	*horde;

	if (n < 1)
		return (NULL);
	horde = new Zombie[n];
	for (int i = 0; i < n; i++)
		horde[i].set_name(name);
	return (horde);
}