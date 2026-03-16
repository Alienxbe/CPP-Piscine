/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 18:07:55 by marykman          #+#    #+#             */
/*   Updated: 2026/03/15 00:12:33 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>

typedef enum e_type
{
	CHAR,	// 0
	FLOAT,	// 1
	DOUBLE,	// 2
	INT,	// 3
	ERROR_TYPE
}	t_type;

class ScalarConverter
{
	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &rhs);
		~ScalarConverter();
		

	public:
		static void	convert(std::string const &litteral);
};

#endif /* SCALARCONVERTER_HPP */
