/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 04:10:52 by marykman          #+#    #+#             */
/*   Updated: 2026/05/30 05:40:39 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc <= 1)
		return (1);

	BitcoinExchange	btc;

	btc.loadDatabase("data.csv");
	btc.processInputFile(argv[1]);

	return 0;
}
