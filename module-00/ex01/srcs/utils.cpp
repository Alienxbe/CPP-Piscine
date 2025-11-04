/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 03:18:27 by marykman          #+#    #+#             */
/*   Updated: 2025/11/04 04:45:03 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

std::string	truncate(std::string str, size_t width)
{
	if (str.length() > width)
		return (str.substr(0, width - 1) + ".");
	return (str);
}

bool		is_number(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
		if (!std::isdigit(str[i]))
			return (false);
	return (true);
}
