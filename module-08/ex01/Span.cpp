/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 03:57:58 by marykman          #+#    #+#             */
/*   Updated: 2026/05/28 18:33:51 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <climits>

////// CONSTRUCTORS //////

Span::Span(unsigned int N): _N(N)
{
}

Span::Span(const Span &other)
{
	*this = other;
}

Span &Span::operator=(const Span &rhs)
{
	if (this != &rhs)
	{
		this->_N = rhs._N;
		this->_data = rhs._data;
	}
	return (*this);
}

Span::~Span()
{
}

////// METHODS //////

void Span::addNumber(int n)
{
	if (_data.size() >= _N)
		throw std::out_of_range("Span is full");

	_data.push_back(n);
}

int Span::shortestSpan(void) const
{
	if (this->_data.size() < 2)
		throw std::logic_error("Not enough elements");

	std::vector<int> sorted = this->_data;
	std::sort(sorted.begin(), sorted.end());

	int minSpan = INT_MAX;
	for (unsigned int i = 1; i < sorted.size(); ++i)
	{
		int diff = sorted[i] - sorted[i - 1];

		if (diff < minSpan)
			minSpan = diff;
	}
	return (minSpan);
}

int Span::longestSpan(void) const
{
	if (this->_data.size() < 2)
		throw std::logic_error("Not enough elements");

	std::vector<int>::const_iterator minIt;
	std::vector<int>::const_iterator maxIt;

	minIt = std::min_element(this->_data.begin(), this->_data.end());
	maxIt = std::max_element(this->_data.begin(), this->_data.end());

	return (*maxIt - *minIt);
}

std::vector<int> const &Span::getData(void) const
{
	return (this->_data);
}

////// COUT //////

std::ostream &operator<<(std::ostream &o, Span const &rhs)
{
	std::vector<int> const &data = rhs.getData();

	o << "[";

	for (unsigned int i = 0; i < data.size(); ++i)
	{
		o << data[i];

		if (i + 1 < data.size())
			o << ", ";
	}

	o << "]";
	return (o);
}