/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 03:45:35 by marykman          #+#    #+#             */
/*   Updated: 2025/11/16 23:12:25 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>

class Bureaucrat;

class Form
{
	private:
		std::string const	_name;
		bool				_signed;
		int const			_wgrade;
		int const			_xgrade;

	public:
		// Constructors
		Form(void);
		Form(std::string name, int const wgrade, int xgrade);
		Form(Form const &other);
		~Form();

		// Assignement operator
		Form	&operator=(Form const &rhs);

		// Getter
		std::string const	&getName(void) const;
		bool				isSigned(void) const;
		int					getWgrade(void) const;
		int					getXgrade(void) const;

		// Methods
		void	beSigned(Bureaucrat const &b);

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

std::ostream	&operator<<(std::ostream &o, Form const &form);

#endif
