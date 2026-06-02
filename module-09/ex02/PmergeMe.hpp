/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 02:59:37 by marykman          #+#    #+#             */
/*   Updated: 2026/06/02 08:32:32 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <algorithm>
# include <cstdlib>
# include <stdexcept>
# include <string>
# include <sys/time.h>
# include <cmath>


// COMPARISONS COUNTER
static size_t g_comparisons = 0;


////// HELPER //////

/* Gives an index of the nth Jacobsthal number, starting from 1.
 * round((pow(2, n) + pow(-1, n - 1)) / 3) means that it starts from 0.*/
long	jacobsthal_number(long n)
{
	return round((pow(2, n + 1) + pow(-1, n)) / 3);
}

template <typename Iterator>
bool	comp(Iterator lv, Iterator rv)
{
	g_comparisons++;
	return (*lv < *rv);
}

template <typename Iterator>
Iterator	next(Iterator it, int steps)
{
	std::advance(it, steps);
	return it;
}

template <typename Iterator>
void	swap_pair(Iterator it, int pair_level)
{
	Iterator start = next(it, -pair_level + 1);
	Iterator end = next(start, pair_level);
	while (start != end)
	{
		std::iter_swap(start, next(start, pair_level));
		start++;
	}
}

template <typename Iterator>
void	show_pair(Iterator it, int pair_level)
{
	if (pair_level <= 0)
		return;

	Iterator start = next(it, -pair_level + 1);
	Iterator end = next(start, pair_level);

	std::cout << "pair content: ";
	if (start != end)
	{
		std::cout << *start;
		Iterator current = next(start, 1);
		while (current != end)
		{
			std::cout << " " << *current;
			++current;
		}
	}
	std::cout << std::endl;
}

////// ALGO //////

template <typename Container>
void	merge_insertion_sort(Container& container, int pair_level)
{
	// Recursion stop
	int pair_units_nbr = container.size() / pair_level;
	if (pair_units_nbr < 2)
		return;

	typedef typename Container::iterator Iterator;

	bool is_odd = pair_units_nbr % 2 == 1;

	Iterator start = container.begin();
	Iterator last = next(container.begin(), pair_level * (pair_units_nbr));
	Iterator end = next(last, -(is_odd * pair_level));

	/* Swap pairs of numbers, pairs, pairs of pairs etc by the biggest pair
		number. After each swap we recurse. */
	int jump = 2 * pair_level;
	for (Iterator it = start; it != end; std::advance(it, jump))
	{
		Iterator this_pair = next(it, pair_level - 1);
		Iterator next_pair = next(it, pair_level * 2 - 1);
		if (comp(next_pair, this_pair))
			swap_pair(this_pair, pair_level);
	}

	// Recursion
	merge_insertion_sort(container, pair_level * 2);

	/* This part of the code is only executed when recursion ends */

	/* Main contains an already sorted sequence.
	   Pend stores yet to be sorted numbers.
	   They contain iterators instead of the numbers themselves because
	   iterators + pair_level contain all the information about any stored
	   range of numbers. */
	std::vector<Iterator>	main;
	std::vector<Iterator>	pend;

	/* Initialize the main chain with the {b1, a1}. */
	main.insert(main.end(), next(container.begin(), pair_level - 1));
	main.insert(main.end(), next(container.begin(), pair_level * 2 - 1));

	// std::cout << "=== " << pair_level << " ===" << std::endl;

	/* Insert the rest of a's into the main chain.
	   Insert the rest of b's into the pend. */
	for (int i = 4; i <= pair_units_nbr; i += 2)
	{
		pend.insert(pend.end(), next(container.begin(), pair_level * (i - 1) - 1));
		main.insert(main.end(), next(container.begin(), pair_level * i - 1));
	}

	/* Insert an odd element to the pend, if there are any. */
	if (is_odd)
	{
		pend.insert(pend.end(), next(end, pair_level - 1));
	}

	// std::cout << "In Main:" << std::endl;
	// for (typename std::vector<Iterator>::iterator it = main.begin(); it != main.end(); ++it)
	// 	show_pair(*it, pair_level);

	// std::cout << "In Pend:" << std::endl;
	// for (typename std::vector<Iterator>::iterator it = pend.begin(); it != pend.end(); ++it)
	// 	show_pair(*it, pair_level);

		/* Insert the pend into the main in the order determined by the
	   Jacobsthal numbers. For example: 3 2 -> 5 4 -> 11 10 9 8 7 6 -> etc.
	   During insertion, elements from the main chain serve as an upper bound for inserting elements,
	   in order to save number of comparisons, as we know already that, for example,
	   b5 is lesser than a5, we binary search only until a5, not until the end of the container.

	   We can calculate the index of the bound element. With the way I do it,
	   the index of the bound is inserted_numbers + current_jacobsthal_number. */
	int prev_jacobsthal = jacobsthal_number(1);
	int inserted_numbers = 0;
	for (int k = 2;; k++)
	{
		int curr_jacobsthal = jacobsthal_number(k);
		int jacobsthal_diff = curr_jacobsthal - prev_jacobsthal;
		int offset = 0;
		if (jacobsthal_diff > static_cast<int>(pend.size()))
			break;
		int nbr_of_times = jacobsthal_diff;
		typename std::vector<Iterator>::iterator pend_it = next(pend.begin(), jacobsthal_diff - 1);
		typename std::vector<Iterator>::iterator bound_it =
			next(main.begin(), curr_jacobsthal + inserted_numbers);
		while (nbr_of_times)
		{
			typename std::vector<Iterator>::iterator idx =
				std::upper_bound(main.begin(), bound_it, *pend_it, comp<Iterator>);
			typename std::vector<Iterator>::iterator inserted = main.insert(idx, *pend_it);
			nbr_of_times--;
			pend_it = pend.erase(pend_it);
			std::advance(pend_it, -1);
			offset += (inserted - main.begin()) == curr_jacobsthal + inserted_numbers;
			bound_it = next(main.begin(), curr_jacobsthal + inserted_numbers - offset);
		}
		prev_jacobsthal = curr_jacobsthal;
		inserted_numbers += jacobsthal_diff;
		offset = 0;
	}

	/* Insert the remaining elements in the reversed order. Here we also want to
	   perform as less comparisons as possible, so we calculate the starting bound
	   to insert pend number to be the pair of the first pend number. If the first
	   pend number is b8, the bound is a8, if the pend number is b7, the bound is a7 etc.
	   With the way I do it the index of bound is
	   size_of_main - size_of_pend + index_of_current_pend. */
	for (ssize_t i = pend.size() - 1; i >= 0; i--)
	{
		typename std::vector<Iterator>::iterator curr_pend = next(pend.begin(), i);
		typename std::vector<Iterator>::iterator curr_bound =
			next(main.begin(), main.size() - pend.size() + i + is_odd);
		typename std::vector<Iterator>::iterator idx =
			std::upper_bound(main.begin(), curr_bound, *curr_pend, comp<Iterator>);
		main.insert(idx, *curr_pend);
	}

	/* Use copy vector to store all the numbers, in order not to overwrite the
	   original iterators. */
	std::vector<int> copy;
	copy.reserve(container.size());
	for (typename std::vector<Iterator>::iterator it = main.begin(); it != main.end(); it++)
	{
		for (int i = 0; i < pair_level; i++)
		{
			Iterator pair_start = *it;
			std::advance(pair_start, -pair_level + i + 1);
			copy.insert(copy.end(), *pair_start);
		}
	}

	/* Replace values in the original container. */
	Iterator container_it = container.begin();
	std::vector<int>::iterator copy_it = copy.begin();
	while (copy_it != copy.end())
	{
		*container_it = *copy_it;
		container_it++;
		copy_it++;
	}
	
}

////// UTILS //////

template <typename Container>
void	fill_container(int argc, char** argv, Container& cont)
{
	for (int i = 1; i < argc; ++i) {
		char* end;
		long num = std::strtol(argv[i], &end, 10);
		if (*end != '\0' || num < 0 || num > __INT_MAX__)
			throw std::invalid_argument("Invalid input");
		cont.push_back(static_cast<int>(num));
	}
}

template <typename Container>
double	measure_sort(Container& cont)
{
	struct timeval start;
	struct timeval end;

	gettimeofday(&start, NULL);
	g_comparisons = 0;
	merge_insertion_sort(cont, 1);
	gettimeofday(&end, NULL);

	long seconds  = end.tv_sec  - start.tv_sec;
	long micros   = end.tv_usec - start.tv_usec;

	return static_cast<double>(seconds * 1000000 + micros);
}

#endif /* PMERGEME_HPP */
