/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 05:10:26 by marykman          #+#    #+#             */
/*   Updated: 2025/11/07 08:52:50 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		bool	_guarGateMode;

		ScavTrap(void);									// Canonical form

	public:
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const &other);				// Canonical form
		~ScavTrap();									// Canonical form

		ScavTrap	&operator=(ScavTrap const &rhs);	// Canonical form

		void	attack(std::string const &target);		// Redefinition of parent class
		void	guardGate(void);
};

#endif
