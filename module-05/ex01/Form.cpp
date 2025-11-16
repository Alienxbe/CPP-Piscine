/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 22:25:20 by marykman          #+#    #+#             */
/*   Updated: 2025/11/16 23:13:23 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

////// CONSTRUCTORS //////

Form::Form(void) :
	_name(DEFAULT_NAME),
	_signed(false),
	_wgrade(DEFAULT_GRADE),
	_xgrade(DEFAULT_GRADE)
{
	
}

Form::Form(std::string name, int const wgrade, int xgrade) :
	_name(name),
	_signed(false),
	_wgrade(wgrade),
	_xgrade(xgrade)
{
	if (wgrade < MIN_GRADE || xgrade < MIN_GRADE)
		throw GradeTooHighException();
	if (wgrade > MAX_GRADE || xgrade > MAX_GRADE)
		throw GradeTooLowException();
}

Form::Form(Form const &other) :
	_name(other._name),
	_signed(other._signed),
	_wgrade(other._wgrade),
	_xgrade(other._xgrade)
{
	
}

Form::~Form()
{
	
}

////// OPERATORS //////

Form	&Form::operator=(Form const &rhs)
{
	if (this != &rhs)
	{
		this->_signed = rhs._signed;
	}
	return (*this);
}

////// GETTER //////

std::string const	&Form::getName(void) const
{
	return (this->_name);
}

bool	Form::isSigned(void) const
{
	return (this->_signed);
}

int	Form::getWgrade(void) const
{
	return (this->_wgrade);
}

int	Form::getXgrade(void) const
{
	return (this->_xgrade);
}

////// METHODS //////

void Form::beSigned(Bureaucrat const &b)
{
	if (b.getGrade() <= this->_wgrade)
		this->_signed = true;
	else
		throw GradeTooLowException();
}

////// EXCEPTIONS //////

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}	

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

////// FUNCTIONS //////

std::ostream	&operator<<(std::ostream &o, Form const &f)
{
	o << f.getName() << ", "
		<< ((f.isSigned()) ? "signed" : "unsigned")
		<< " form"
		<< " (grade to sign: " << f.getWgrade()
		<< " | grade to exec: " << f.getXgrade()
		<< ")";
	return (o);
}
