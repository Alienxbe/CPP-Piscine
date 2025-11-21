/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:57:23 by marykman          #+#    #+#             */
/*   Updated: 2025/11/21 10:43:06 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Intern		victime;
	Bureaucrat	boss("boss", 1);
	Bureaucrat	petitBoss("petit boss", 150);
	AForm		*form;

	form = victime.makeForm("presidential pardon", "Macron");
	if (form)
	{
		boss.signForm(*form);
		boss.execForm(*form);
		petitBoss.execForm(*form);
		delete form;
	}
	return (0);
}
