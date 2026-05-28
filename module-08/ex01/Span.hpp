/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 03:54:12 by marykman          #+#    #+#             */
/*   Updated: 2026/05/28 18:39:40 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>
# include <stdexcept>
# include <iostream>

class Span
{
	private:
		unsigned int		_N;
		std::vector<int>	_data;
	
		Span(void);
		

	public:
		Span(unsigned int N);
		Span(const Span &other);
		Span &operator=(const Span &rhs);
		~Span();

		void	addNumber(int n);
		int		shortestSpan(void) const;
		int		longestSpan(void) const;

		std::vector<int> const &getData(void) const;

		template <typename InputIterator>
		void addRange(InputIterator begin, InputIterator end)
		{
			std::size_t distance = std::distance(begin, end);

			if (this->_data.size() + distance > this->_N)
				throw std::out_of_range("Span is full");

			this->_data.insert(this->_data.end(), begin, end);
		}
};

std::ostream &operator<<(std::ostream &o, Span const &rhs);

#endif /* SPAN_HPP */
