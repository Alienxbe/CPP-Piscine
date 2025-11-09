/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 09:11:36 by marykman          #+#    #+#             */
/*   Updated: 2025/11/09 16:00:54 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>

class WrongAnimal
{
	protected:
		std::string	_type;

	public:
		WrongAnimal(void);
		WrongAnimal(std::string const &type);
		WrongAnimal(WrongAnimal const &other);
		virtual ~WrongAnimal();

		// Operator
		WrongAnimal	&operator=(WrongAnimal const &rhs);

		// Non dynamic call
		void	makeSound(void) const;

		// Getter
		std::string const	&getType(void) const;
};

#endif
