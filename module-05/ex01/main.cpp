/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:57:23 by marykman          #+#    #+#             */
/*   Updated: 2025/11/16 23:09:22 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat	b;
	Form		f("LE PAPIER", 10, 15);

	std::cout << b << std::endl;
	std::cout << f << std::endl;
	b.signForm(f);
	return (0);
}
