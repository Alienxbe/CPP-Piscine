/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:05:53 by marykman          #+#    #+#             */
/*   Updated: 2025/11/17 17:09:30 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string const	_target;

		// Constructors
		RobotomyRequestForm(void);

		// Assignement operator
		RobotomyRequestForm	&operator=(RobotomyRequestForm const &rhs);

		// Methods
		void	applyForm(void) const;
		
	public:
		// Constructors
		RobotomyRequestForm(std::string const &target);
		RobotomyRequestForm(RobotomyRequestForm const &other);
		~RobotomyRequestForm();
};

#endif
