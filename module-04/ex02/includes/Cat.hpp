/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:45:40 by marykman          #+#    #+#             */
/*   Updated: 2025/11/09 17:22:02 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain	*_brain;

	public:
		Cat(void);
		Cat(Cat const &other);
		~Cat();

		Cat	&operator=(Cat const &rhs);

		void	makeSound(void) const;
		
		// Getter and setter
		std::string const	&getIdea(size_t index) const;
		void				setIdea(size_t index, std::string const &idea);
};

#endif
