/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:52:31 by marykman          #+#    #+#             */
/*   Updated: 2025/11/17 17:13:28 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

# define MAX_GRADE		150
# define MIN_GRADE		1

class Bureaucrat
{
	private:
		std::string const	_name;
		int					_grade;

		// constructors
		Bureaucrat(void);

		// Setter
		void	setGrade(int grade);

	public:
		// constructors
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const &other);
		~Bureaucrat();

		// Assignement operator
		Bureaucrat	&operator=(Bureaucrat const &rhs);

		// Getter
		std::string const	&getName(void) const;
		int					getGrade(void) const;

		// Methods
		void	incrementGrade(void);
		void	decrementGrade(void);
		void	signForm(AForm &f) const;
		void	execForm(AForm const &f) const;

		
		// Exceptions
		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
};

// Functions
std::ostream	&operator<<(std::ostream &o, Bureaucrat const &bureaucrat);

#endif
