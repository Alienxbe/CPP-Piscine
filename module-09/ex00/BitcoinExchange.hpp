/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 17:07:33 by marykman          #+#    #+#             */
/*   Updated: 2026/05/30 05:39:30 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>

class BitcoinExchange
{
	private:
		std::map<std::string, float>	_database;

	public:
		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const &other);
		BitcoinExchange &operator=(BitcoinExchange const &rhs);
		~BitcoinExchange();

		// Database
		void	loadDatabase(char const *filename);

		// Exchange rate
		float	getExchangeRate(std::string const &date) const;
		void	processInputFile(char const *filename);

		// Getter
		std::map<std::string, float> const &	getDatabase(void) const;

};

std::ostream &	operator<<(std::ostream &o, BitcoinExchange const &rhs);

#endif /* BITCOINEXCHANGE_HPP */
