/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 06:40:45 by marykman          #+#    #+#             */
/*   Updated: 2025/11/04 06:48:33 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "---- Addresses ----" << std::endl;
	std::cout << "string    : " << &str << std::endl;
	std::cout << "pointer   : " << stringPTR << std::endl;
	std::cout << "reference : " << &stringREF << std::endl;

	std::cout << "----- Values ------" << std::endl;
	std::cout << "string    : " << str << std::endl;
	std::cout << "pointer   : " << *stringPTR << std::endl;
	std::cout << "reference : " << stringREF << std::endl;

	return (0);
}