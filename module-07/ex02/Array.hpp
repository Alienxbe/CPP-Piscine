/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 06:33:23 by marykman          #+#    #+#             */
/*   Updated: 2026/04/20 16:15:12 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstddef>
# include <exception>

template<typename T>
class Array
{
	private:
		T*				_data;
		unsigned int	_size;

	public:
		// Default constructor
		Array(void) : _data(NULL), _size(0) {}

		// Constructor with size
		Array(unsigned int size) : _data(NULL), _size(size)
		{
			if (_size > 0)
				_data = new T[size]();
		}
		
		// Copy constructor (deep copy)
		Array(const Array &other) : _data(NULL), _size(other._size)
		{
			if (_size > 0)
			{
				_data = new T[_size]();
				for (unsigned int i = 0; i < _size; i++)
					_data[i] = other._data[i];
			}
		}

		// Assignement operator (deep copy)
		Array &operator=(const Array &rhs)
		{
			if (this == &rhs)
				return (*this);
		
			delete[] _data;	// Free old memory

			_size = rhs._size;
			_data = NULL;

			if (_size > 0)
			{
				_data = new T[_size]();
				for (unsigned int i = 0; i < _size; i++)
					_data[i] = rhs._data[i];
			}
			return (*this);
		}
		
		~Array()
		{
			delete[] _data;
		};

		/// ACCESSOR ///
		
		T	&operator[](unsigned int index)
		{
			if (index >= _size)
				throw std::exception();
			return _data[index];
   		}

		T const	&operator[](unsigned int index) const
		{
			if (index >= _size)
				throw std::exception();
			return _data[index];
   		}

		unsigned int	size(void) const
		{
			return (_size);
		}

};

#endif /* ARRAY_HPP */

