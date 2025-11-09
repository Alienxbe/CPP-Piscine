/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:27:56 by marykman          #+#    #+#             */
/*   Updated: 2025/11/09 17:27:00 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain	*_brain;

	public:
		Dog(void);
		Dog(Dog const &other);
		~Dog();

		Dog	&operator=(Dog const &rhs);

		void	makeSound(void) const;

		// Getter and setter
		std::string const	&getIdea(size_t index) const;
		void				setIdea(size_t index, std::string const &idea);
};

#endif
