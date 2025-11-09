/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 16:31:27 by marykman          #+#    #+#             */
/*   Updated: 2025/11/09 17:32:26 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class Brain
{
	private:
		std::string	_ideas[100];

	public:
		Brain(void);
		Brain(Brain const &other);
		~Brain();

		Brain	&operator=(Brain const &rhs);

		// Getter and setter
		std::string const	&getIdea(size_t index) const;
		void				setIdea(size_t index, std::string const &idea);
};

#endif
