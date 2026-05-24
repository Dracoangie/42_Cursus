/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 11:33:47 by angnavar          #+#    #+#             */
/*   Updated: 2026/05/24 23:03:50 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <stack>
#include <iterator>
#include <vector>
#include <list>

class PmergeMe
{
	std::vector<int>	vec;
	std::list<int>		list;

public:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe &operator=(const PmergeMe& other);
	~PmergeMe();

	void vecOrder(std::vector<int>	other);
	void lsitOrder(std::list<int>	other);
};

#endif