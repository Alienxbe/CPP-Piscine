/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:16:15 by marykman          #+#    #+#             */
/*   Updated: 2025/11/17 17:09:36 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string const	_target;
	
		// Constructors
		PresidentialPardonForm(void);

		// Assignement operator
		PresidentialPardonForm	&operator=(PresidentialPardonForm const &rhs);

		// Methods
		void	applyForm(void) const;

	public:
		// Constructors
		PresidentialPardonForm(std::string const &target);
		PresidentialPardonForm(PresidentialPardonForm const &other);
		~PresidentialPardonForm();
};

#endif