/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:14:36 by marykman          #+#    #+#             */
/*   Updated: 2025/11/17 20:11:50 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <sstream>
#include "ShrubberyCreationForm.hpp"

////// utils //////

std::string	file_to_str(std::ifstream &infile)
{
	
	std::stringstream	buffer;

	if (infile.fail())
	{
		std::cerr << "Error with file opening" << std::endl;
		return ("");
	}
	buffer << infile.rdbuf();
	return (buffer.str());
}

////// Constructors //////

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) :
	AForm("ShrubberyCreation", 145, 137),
	_target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) :
	AForm(other),
	_target(other._target)
{
	
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	
}

////// Methods //////

void ShrubberyCreationForm::applyForm(void) const
{
	std::ofstream	file(std::string(this->_target + "_shrubbery").c_str());
	std::ifstream	tree("christmas_tree.ascii");
	
	file << file_to_str(tree);
}
