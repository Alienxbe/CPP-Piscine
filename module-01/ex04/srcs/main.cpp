/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 07:52:06 by marykman          #+#    #+#             */
/*   Updated: 2025/11/07 00:32:46 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>

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

std::string	&str_replace(std::string &str, std::string s1, std::string s2)
{
	size_t	pos;

	pos = 0;
	while ((pos = str.find(s1, pos)) != std::string::npos)
	{
		str.erase(pos, s1.length());
		str.insert(pos, s2);
		pos += s2.length();
	}
	return (str);
}

// ./sed [filename] [s1] [s2]
int main(int argc, char const *argv[])
{
	
	if (argc != 4 || !strlen(argv[2]))
	{
		std::cerr << "Wrong argument count" << std::endl;
		std::cerr << "Usage: ./sed <filename> <s1> <s2>" << std::endl;
		return (1);
	}

	std::ifstream	infile(argv[1]);
	std::string		file = file_to_str(infile);

	if (infile.fail())
		return (1);

	std::string		outfilename(argv[1]);
	outfilename.append(".replace");
	std::ofstream	outfile(outfilename.c_str());

	if (outfile.fail())
		return (1);
	
	file = str_replace(file, argv[2], argv[3]);
	outfile << file;

	return 0;
}
