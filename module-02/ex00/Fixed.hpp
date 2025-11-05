/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 01:50:26 by marykman          #+#    #+#             */
/*   Updated: 2025/11/05 02:25:05 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	private:
		int					_n;
		static const int	_fractional_bit;

	public:
		Fixed(void);							// default constructor
		Fixed(Fixed const &src);				// Copy constructor
		~Fixed();								// Destructor
		Fixed	&operator=(const Fixed &rhs);	// Assignement operator overload

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
