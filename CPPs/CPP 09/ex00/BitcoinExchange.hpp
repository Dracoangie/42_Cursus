/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 12:23:07 by angnavar          #+#    #+#             */
/*   Updated: 2026/05/24 20:17:26 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cstdlib>

class BitcoinExchange {

	private:
		std::map<std::string, float> _db;
		bool	isValidDate(std::string const &date) const;
	
	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &copy);
		BitcoinExchange &operator=(BitcoinExchange const &copy);
		~BitcoinExchange();

		void	loadDatabase(std::string const &filename);
		void	processInput(std::string const &filename);
		float	getPrice(std::string const &date) const;
};

#endif