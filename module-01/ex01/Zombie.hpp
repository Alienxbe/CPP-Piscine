/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 05:52:32 by marykman          #+#    #+#             */
/*   Updated: 2025/11/04 06:15:13 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Zombie
{

	private:
		std::string	name;

	public:
		Zombie(void);
		~Zombie(void);

		void	announce(void);
		void	set_name(std::string name);
};

Zombie* zombieHorde(int n, std::string name);
