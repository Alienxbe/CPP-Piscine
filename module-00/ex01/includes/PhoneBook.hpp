/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:11:47 by marykman          #+#    #+#             */
/*   Updated: 2025/06/24 18:13:48 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Contact.hpp"

#define MAX_CONTACT	8

class PhoneBook
{
	private:
		Contact	_contacts[MAX_CONTACT];
	public:
		PhoneBook(void);
		~PhoneBook();
};
