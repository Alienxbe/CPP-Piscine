/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 10:19:01 by marykman          #+#    #+#             */
/*   Updated: 2025/11/21 10:42:13 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

////// CANONICAL FORM //////

Intern::Intern(void)
{

}

Intern::Intern(const Intern &other)
{
	(void)other;
}

Intern	&Intern::operator=(const Intern &rhs)
{
	(void)rhs;
	return (*this);
}

Intern::~Intern()
{
	
}

////// METHODS //////

static AForm	*makeShrubbery(std::string const &target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm	*makeRobotomy(std::string const &target)
{
	return (new RobotomyRequestForm(target));
}

static AForm	*makePresidential(std::string const &target)
{
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeForm(std::string name, std::string target)
{
	std::string	names[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm	*(*fct[])(std::string const &) = {&makeShrubbery, &makeRobotomy, &makePresidential};

	for (int i = 0; i < 3; i++)
	{
		if (names[i] == name)
		{
			AForm *form = fct[i](target);
			std::cout << "Intern creates " << *form << std::endl;
			return (form);
		}
	}

	std::cout << "Intern didn't find any corresponding form..." << std::endl; 
	return (NULL);
}
