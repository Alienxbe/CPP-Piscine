/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 05:27:23 by marykman          #+#    #+#             */
/*   Updated: 2025/11/04 05:39:52 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

// Variable initialisation

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Constructor / Destructor

Account::Account(int initial_deposit)
{
	
}

Account::~Account(void)
{

}

// static methods

int Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	
}

// Public Methods

void	Account::makeDeposit(int deposit)
{

}

bool	Account::makeWithdrawal(int withdrawal)
{
	
}

int		Account::checkAmount(void) const
{

}

void	Account::displayStatus(void) const
{
	
}

// Private methods

Account::Account(void)
{
	
}

void	Account::_displayTimestamp(void)
{
	
}

