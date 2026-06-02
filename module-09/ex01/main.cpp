/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 13:42:46 by marykman          #+#    #+#             */
/*   Updated: 2026/05/31 13:42:46 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <sstream>
#include <string>

static bool isNumber(std::string const &token)
{
	if (token.length() != 1)
		return false;
	return (token[0] >= '0' && token[0] <= '9');
}

static bool isOperator(std::string const &token)
{
	return (token.length() == 1 &&
		(token[0] == '+' || token[0] == '-' ||
		 token[0] == '*' || token[0] == '/'));
}

static int applyOp(int a, int b, char op, bool &error)
{
	switch (op)
	{
		case '+':
			return b + a;
		case '-':
			return b - a;
		case '*':
			return b * a;
		case '/':
			if (a == 0)
			{
				error = true;
				return 0;
			}
			return b / a;
		default:
			error = true;
			return 0;
	}
}

static bool evaluateRPN(std::string const &expr, int &result)
{
	std::stack<int> stack;
	std::istringstream ss(expr);
	std::string token;
	bool error = false;

	while (ss >> token)
	{
		if (isNumber(token))
			stack.push(token[0] - '0');
		else if (isOperator(token))
		{
			if (stack.size() < 2)
				return false;

			int a = stack.top();
			stack.pop();
			int b = stack.top();
			stack.pop();

			int res = applyOp(a, b, token[0], error);
			if (error == true)
				return false;

			stack.push(res);
		}
		else
			return false;
	}

	if (stack.size() != 1)
		return false;

	result = stack.top();
	return true;
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	int result = 0;

	if (evaluateRPN(argv[1], result) == false)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	std::cout << result << std::endl;
	return 0;
}