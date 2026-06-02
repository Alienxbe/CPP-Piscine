/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 04:10:52 by marykman          #+#    #+#             */
/*   Updated: 2026/05/31 12:55:40 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
		return (1);

	BitcoinExchange	btc;

	btc.loadDatabase("data.csv");
	btc.processInputFile(argv[1]);

	return (0);
}
