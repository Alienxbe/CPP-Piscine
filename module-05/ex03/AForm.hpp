/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 03:45:35 by marykman          #+#    #+#             */
/*   Updated: 2025/11/17 17:09:08 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <iostream>

class Bureaucrat;

class AForm
{
	private:
		std::string const	_name;
		bool				_signed;
		int const			_wgrade;
		int const			_xgrade;

		// Constructors
		AForm(void);
		
		// Assignement operator
		AForm	&operator=(AForm const &rhs);


	protected:
		// Abstract method
		virtual void	applyForm(void) const = 0;


	public:
		// Constructors
		AForm(std::string name, int const wgrade, int xgrade);
		AForm(AForm const &other);
		virtual ~AForm();

		// Getter
		std::string const	&getName(void) const;
		bool				isSigned(void) const;
		int					getWgrade(void) const;
		int					getXgrade(void) const;

		// Methods
		void	beSigned(Bureaucrat const &b);
		void	execute(Bureaucrat const &executor) const;
	
		
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
		
		class UnsignedFormException: public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &o, AForm const &form);

#endif
