/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 07:52:06 by marykman          #+#    #+#             */
/*   Updated: 2025/11/04 08:02:17 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

// ./sed [filename] [s1] [s2]
int main(int argc, char const *argv[])
{
	
	if (argc != 4)
	{
		std::cout << "Wrong argument count" << std::endl;
		std::cout << "Usage: ./sed <ilename> <s1> <s2>" << std::endl;
		return (1);
	}
	
	return 0;
}
