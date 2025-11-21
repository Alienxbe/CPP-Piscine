/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:57:23 by marykman          #+#    #+#             */
/*   Updated: 2025/11/17 20:44:09 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	{	// Shrubbery Creation Form tests (145, 137)
		std::cout << "\t[ Shrubbery Creation Form ]" << std::endl;

		ShrubberyCreationForm	form1("Garden");
		ShrubberyCreationForm	form2("Forest");
		Bureaucrat				boss("boss", 1);
		Bureaucrat				bob("bob", 138);

		std::cout << form1 << std::endl
			<< form2 << std::endl
			<< boss << std::endl
			<< bob << std::endl << std::endl;

		bob.execForm(form1);	// Form is not signed yet
		bob.signForm(form1);
		bob.execForm(form1);	// Can't execute form
		boss.execForm(form1);

		std::cout << std::endl;

		bob.incrementGrade();	// Bob can now execute Shrubbery
		std::cout << bob << std::endl;

		bob.signForm(form2);
		bob.execForm(form2);

		std::cout << std::endl;
	}

	{	// Robotomy Creation Form tests (75, 45)
		std::cout << "\t[ Robotomy Creation Form ]" << std::endl;

		RobotomyRequestForm	form1("Macron");
		RobotomyRequestForm	form2("Trump");
		Bureaucrat			boss("boss", 1);
		Bureaucrat			bob("bob", 44);

		std::cout << form1 << std::endl
			<< form2 << std::endl
			<< boss << std::endl
			<< bob << std::endl << std::endl;

		bob.execForm(form1);	// Form is not signed yet
		bob.signForm(form1);
		bob.execForm(form1);	// Can't execute form
		boss.execForm(form1);

		std::cout << std::endl;

		bob.incrementGrade();	// Bob can now execute Robotomymake

		std::cout << bob << std::endl;

		bob.signForm(form2);
		bob.execForm(form2);

		std::cout << std::endl;
	}

	{	// Presidential Creation Form tests (25, 5)
		std::cout << "\t[ Presidential Creation Form ]" << std::endl;

		PresidentialPardonForm	form1("Steve");
		PresidentialPardonForm	form2("Alex");
		Bureaucrat				boss("boss", 1);
		Bureaucrat				bob("bob", 6);

		std::cout << form1 << std::endl
			<< form2 << std::endl
			<< boss << std::endl
			<< bob << std::endl << std::endl;

		bob.execForm(form1);	// Form is not signed yet
		bob.signForm(form1);
		bob.execForm(form1);	// Can't execute form
		boss.execForm(form1);

		std::cout << std::endl;

		bob.incrementGrade();	// Bob can now execute Shrubbery
		std::cout << bob << std::endl;

		bob.signForm(form2);
		bob.execForm(form2);

		std::cout << std::endl;
	}
	
	return (0);
}
