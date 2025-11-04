/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:11:47 by marykman          #+#    #+#             */
/*   Updated: 2025/11/04 03:26:50 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Contact.hpp"

#define MAX_CONTACT	8

class PhoneBook
{
	private:
		Contact			_contacts[MAX_CONTACT];
		unsigned int	count;
		unsigned int	index;

		void			display();

	public:
		PhoneBook(void);
		~PhoneBook();

		void	add_contact();
		void	search();
};
