/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 19:40:51 by marykman          #+#    #+#             */
/*   Updated: 2026/05/29 01:28:17 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>

#include "MutantStack.hpp"

static void	testMutantStack(void)
{
	std::cout << "=== MutantStack test ===" << std::endl;

	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "top(): " << mstack.top() << std::endl;

	mstack.pop();

	std::cout << "size(): " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(42);
	mstack.push(0);

	std::cout << "\nForward iteration:" << std::endl;

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << "\nReverse iteration:" << std::endl;

	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();

	while (rit != rite)
	{
		std::cout << *rit << std::endl;
		++rit;
	}
}

static void	testList(void)
{
	std::cout << "\n=== std::list test ===" << std::endl;

	std::list<int>	list;

	list.push_back(5);
	list.push_back(17);

	std::cout << "back(): " << list.back() << std::endl;

	list.pop_back();

	std::cout << "size(): " << list.size() << std::endl;

	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(42);
	list.push_back(0);

	std::cout << "\nForward iteration:" << std::endl;

	std::list<int>::iterator it = list.begin();
	std::list<int>::iterator ite = list.end();

	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << "\nReverse iteration:" << std::endl;

	std::list<int>::reverse_iterator rit = list.rbegin();
	std::list<int>::reverse_iterator rite = list.rend();

	while (rit != rite)
	{
		std::cout << *rit << std::endl;
		++rit;
	}
}

void	simpleTest(void)
{
	testMutantStack();

	std::cout << "\n--------------------------------\n" << std::endl;

	testList();

}

#include <iostream>
#include <list>

#include "MutantStack.hpp"

#include <iostream>
#include <list>

#include "MutantStack.hpp"

template <typename Container>
void	printForward(Container const &container)
{
	typename Container::const_iterator it = container.begin();
	typename Container::const_iterator ite = container.end();

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

template <typename Container>
void	printReverse(Container const &container)
{
	typename Container::const_reverse_iterator it = container.rbegin();
	typename Container::const_reverse_iterator ite = container.rend();

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

static void	fillMutantStack(MutantStack<int> &mstack)
{
	mstack.push(5);
	mstack.push(17);

	std::cout << "top(): " << mstack.top() << std::endl;

	mstack.pop();

	std::cout << "size(): " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(42);
	mstack.push(0);
}

static void	fillList(std::list<int> &list)
{
	list.push_back(5);
	list.push_back(17);

	std::cout << "back(): " << list.back() << std::endl;

	list.pop_back();

	std::cout << "size(): " << list.size() << std::endl;

	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(42);
	list.push_back(0);
}

int	main(void)
{
	MutantStack<int>	mstack;
	std::list<int>		list;

	std::cout << "=== MutantStack ===" << std::endl;

	fillMutantStack(mstack);

	std::cout << "\nForward iteration:" << std::endl;
	printForward(mstack);

	std::cout << "\nReverse iteration:" << std::endl;
	printReverse(mstack);

	std::cout << "\n--------------------------------\n" << std::endl;

	std::cout << "=== std::list ===" << std::endl;

	fillList(list);

	std::cout << "\nForward iteration:" << std::endl;
	printForward(list);

	std::cout << "\nReverse iteration:" << std::endl;
	printReverse(list);

	return (0);
}
