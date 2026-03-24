/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 05:45:15 by marykman          #+#    #+#             */
/*   Updated: 2026/03/24 05:46:23 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATES_HPP
# define TEMPLATES_HPP

template<typename T>
void swap(T &a, T &b) {
	T tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
T const &min(T const &a, T const &b) {
	return (a < b ? a : b);
}

template<typename T>
T const &max(T const &a, T const &b) {
	return (a > b ? a : b);
}

#endif /* TEMPLATES_HPP */
