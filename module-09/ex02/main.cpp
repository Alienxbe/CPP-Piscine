/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 02:58:33 by marykman          #+#    #+#             */
/*   Updated: 2026/06/02 08:32:20 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include "PmergeMe.hpp"

template <typename Container>
static void print_sequence(const std::string& prefix, const Container& container)
{
	std::cout << prefix;
	typename Container::const_iterator it = container.begin();
	if (it != container.end()) {
		std::cout << *it;
		++it;
	}
	while (it != container.end()) {
		std::cout << " " << *it;
		++it;
	}
	std::cout << std::endl;
}

template <typename Container>
static void print_result(const std::string& container_name, const Container& cont, double time)
{
	std::cout << "Time to process a range of " << cont.size() 
			  << " elements with " << container_name << " : " 
			  << time << " us (" << g_comparisons << " comparisons)\n";
}

int main(int argc, char** argv)
{
	if (argc < 2) {
		std::cerr << "Error: No arguments provided" << std::endl;
		return (1);
	}
	
	try {
		std::vector<int> vec;
		std::deque<int> deq;

		fill_container(argc, argv, vec);
		fill_container(argc, argv, deq);

		print_sequence("Before: ", vec);
	
		double vec_time = measure_sort(vec);
		double deq_time = measure_sort(deq);
		
		print_sequence("After: ", vec);
		print_result("std::vector", vec, vec_time);
		print_result("std::deque ", deq, deq_time);
	}
	catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}