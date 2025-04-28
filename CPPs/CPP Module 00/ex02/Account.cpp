/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:28:31 by angnavar          #+#    #+#             */
/*   Updated: 2025/04/21 18:36:32 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	to check differences
//
//	./Account | sed 's/^\[[0-9_]*\] //' | 
//	diff -u <(sed 's/^\[[0-9_]*\] //' 19920104_091532.log) -
//

#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

// static ints def

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// static functions

int	Account::getNbAccounts()
{
	return(_nbAccounts);
}

int	Account::getTotalAmount()
{
	return(_totalAmount);
}

int	Account::getNbDeposits()
{
	return(_totalNbDeposits);
}

int	Account::getNbWithdrawals()
{
	return(_totalNbWithdrawals);
}

//[19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
void	Account::displayAccountsInfos()
{
	if(_nbAccounts == 0)
		return;
	Account::_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts 
		<< ";total:" << _totalAmount
		<< ";deposits:" << _totalNbDeposits
		<< ";withdrawals:" << _totalNbWithdrawals << "\n";
}

// public functions

//[19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
void	Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex 
		<< ";p_amount:" << _amount;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits ++;
	_totalNbDeposits++;
	std::cout	<< ";deposit:" << deposit
		<< ";amount:" << _amount
		<< ";nb_deposits:" << _nbDeposits << "\n";
}

//[19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
bool	Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex 
		<< ";p_amount:" << _amount;
	if(_amount - withdrawal < 0)
	{
		std::cout << ";withdrawal:refused\n";
		return(false);
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals ++;
	_totalNbWithdrawals++;
	std::cout	<< ";withdrawal:" << withdrawal
		<< ";amount:" << _amount
		<< ";nb_withdrawals:" << _nbWithdrawals << "\n";
	return(true);
}

int	Account::checkAmount() const
{
	return(_amount);
}

//[19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
void	Account::displayStatus() const
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex 
		<< ";amount:" << _amount
		<< ";deposits:" << _nbDeposits
		<< ";withdrawals:" << _nbWithdrawals << "\n";
}

// private functions

void	Account::_displayTimestamp()
{
	std::time_t now = std::time(NULL);
	std::tm *lt = std::localtime(&now);

	char buffer[20];
	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", lt);
	std::cout << buffer;
}


// constructor / destructor

//[19920104_091532] index:0;amount:42;created
Account::Account(int initial_deposit)
{
	_nbAccounts++;
	_accountIndex = _nbAccounts -1;

	_amount = initial_deposit;
	_totalAmount = _totalAmount + initial_deposit;

	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex 
		<< ";amount:" << _amount
		<< ";created\n";
};

//[19920104_091532] index:7;amount:8942;closed
Account::~Account()
{
		Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex 
		<< ";amount:" << _amount
		<< ";closed\n";
};