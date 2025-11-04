/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 06:51:02 by marykman          #+#    #+#             */
/*   Updated: 2025/11/04 07:22:18 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class Weapon
{
	private:
		std::string	_type;

	public:
		Weapon(std::string type);
		~Weapon();

		std::string	const	&getType(void);
		void				setType(std::string type);
};

