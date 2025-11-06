/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 19:33:14 by marykman          #+#    #+#             */
/*   Updated: 2025/11/07 00:47:18 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int main(int argc, char const *argv[])
{
	Harl		harl;
	
	if (argc != 2){
		std::cout << "Wrong argument count" << std::endl;
		std::cout << "Usage : ./harl <level>" << std::endl;
		return (1);
	}
	harl.complain(argv[1]);
	return (0);
}
