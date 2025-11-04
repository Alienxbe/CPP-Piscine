/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 07:08:27 by marykman          #+#    #+#             */
/*   Updated: 2025/11/04 07:45:35 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"

class HumanA
{
	private:
		std::string	_name;
		Weapon		&_weapon;
		
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA(void);

		void	attack(void);
};
