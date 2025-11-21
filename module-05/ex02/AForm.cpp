/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 22:25:20 by marykman          #+#    #+#             */
/*   Updated: 2025/11/17 17:10:57 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

////// CONSTRUCTORS //////

AForm::AForm(std::string name, int const wgrade, int xgrade) :
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

AForm::AForm(AForm const &other) :
	_name(other._name),
	_signed(other._signed),
	_wgrade(other._wgrade),
	_xgrade(other._xgrade)
{
	
}

AForm::~AForm()
{
	
}

////// GETTER //////

std::string const	&AForm::getName(void) const
{
	return (this->_name);
}

bool	AForm::isSigned(void) const
{
	return (this->_signed);
}

int	AForm::getWgrade(void) const
{
	return (this->_wgrade);
}

int	AForm::getXgrade(void) const
{
	return (this->_xgrade);
}

////// METHODS //////

void AForm::beSigned(Bureaucrat const &b)
{
	if (b.getGrade() <= this->_wgrade)
		this->_signed = true;
	else
		throw GradeTooLowException();
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!this->_signed)
		throw UnsignedFormException();
	if (executor.getGrade() > this->_xgrade)
		throw GradeTooLowException();
	applyForm();
}

////// EXCEPTIONS //////

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}	

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

const char *AForm::UnsignedFormException::what() const throw()
{
	return ("Form is not signed");
}

////// FUNCTIONS //////

std::ostream	&operator<<(std::ostream &o, AForm const &f)
{
	o << f.getName() << ", "
		<< ((f.isSigned()) ? "signed" : "unsigned")
		<< " form"
		<< " (grade to sign: " << f.getWgrade()
		<< " | grade to exec: " << f.getXgrade()
		<< ")";
	return (o);
}
