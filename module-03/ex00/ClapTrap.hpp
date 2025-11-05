/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 05:17:03 by marykman          #+#    #+#             */
/*   Updated: 2025/11/05 05:54:10 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap
{
	private:
		std::string	_name;
		int			_hp;
		int			_energy;
		int			_attack;

		ClapTrap(void);									// canonical form

	public:
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const &other);				// canonical form
		~ClapTrap();									// canonical form

		ClapTrap	&operator=(ClapTrap const &rhs);	// canonical form

		void	attack(std::string const &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif