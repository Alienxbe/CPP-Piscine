/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 05:55:32 by marykman          #+#    #+#             */
/*   Updated: 2026/03/24 06:32:06 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template<typename T>
void	iter(T *array, size_t const size, void (*f)(T&))
{
	for (size_t i = 0; i < size; i++)
		f(array[i]);
}

template<typename T>
void	iter(T *array, size_t const size, void (*f)(T const &))
{
	for (size_t i = 0; i < size; i++)
		f(array[i]);
}

#endif /* ITER_HPP */
