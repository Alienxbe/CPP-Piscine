/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 19:54:35 by marykman          #+#    #+#             */
/*   Updated: 2026/05/29 01:30:09 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <typename T>
class MutantStack: public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type			container_type;

		typedef typename container_type::iterator				iterator;
		typedef typename container_type::const_iterator			const_iterator;
		
		typedef typename container_type::reverse_iterator		reverse_iterator;
		typedef typename container_type::const_reverse_iterator	const_reverse_iterator;

		MutantStack(void)
		{
		}
		
		MutantStack(MutantStack const &other):
			std::stack<T>(other)
		{
		}

		MutantStack &operator=(MutantStack const &rhs)
		{
			if (this != &rhs)
				std::stack<T>::operator=(rhs);

			return (*this);
		}
		
		~MutantStack()
		{
		}

		/*
		** Normal iterators
		*/

		iterator begin(void)
		{
			return (this->c.begin());
		}

		iterator end(void)
		{
			return (this->c.end());
		}

		const_iterator begin(void) const
		{
			return (this->c.begin());
		}

		const_iterator end(void) const
		{
			return (this->c.end());
		}

		/*
		** Reverse iterators
		*/

		reverse_iterator rbegin(void)
		{
			return (this->c.rbegin());
		}

		reverse_iterator rend(void)
		{
			return (this->c.rend());
		}

		const_reverse_iterator rbegin(void) const
		{
			return (this->c.rbegin());
		}

		const_reverse_iterator rend(void) const
		{
			return (this->c.rend());
		}

};

#endif /* MUTANTSTACK_HPP */
