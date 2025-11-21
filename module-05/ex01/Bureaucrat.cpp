/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 18:54:28 by marykman          #+#    #+#             */
/*   Updated: 2025/11/17 17:02:25 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

////// CONSTRUCTORS //////

Bureaucrat::Bureaucrat(std::string name, int grade)
	: _name(name)
{
	setGrade(grade);
}

Bureaucrat::Bureaucrat(Bureaucrat const &other)
	: _name(other._name), _grade(other._grade)
{

}

Bureaucrat::~Bureaucrat()
{
	
}

////// OPERATORS //////

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &rhs)
{
	if (this != &rhs)
	{
		this->_grade = rhs._grade;
	}
	return (*this);
}

////// GETTERS //////

std::string const	&Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

////// SETTERS //////

void	Bureaucrat::setGrade(int grade)
{
	if (grade > MAX_GRADE)
		throw GradeTooLowException();
	if (grade < MIN_GRADE)
		throw GradeTooHighException();
	this->_grade = grade;
}

////// METHODS //////

void	Bureaucrat::incrementGrade(void)
{
	setGrade(this->_grade - 1); // Higher grade is closer to 1 -> grade should decrement
}

void	Bureaucrat::decrementGrade(void)
{
	setGrade(this->_grade + 1); // Lower grade is closer to 150 -> grade should increment
}

void	Bureaucrat::signForm(Form &f)
{
	try
	{
		f.beSigned(*this);
		std::cout << this->_name << " signed " << f.getName() << std::endl;
	}
	catch(const Form::GradeTooLowException &e)
	{
		std::cout << this->_name << " couldn't sign "
			<< f.getName()
			<< " because "
			<< e.what() << std::endl;
	}
	
}

////// EXCEPTIONS //////

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high! (Max grade is 1)");
}	

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low! (Min grade is 150)");
}

////// FUNCTIONS //////

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &b)
{
	o << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (o);
}
