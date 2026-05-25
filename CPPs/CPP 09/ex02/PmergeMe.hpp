/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 11:33:47 by angnavar          #+#    #+#             */
/*   Updated: 2026/05/25 15:19:25 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <stack>
#include <iterator>
#include <vector>
#include <list>
#include <deque>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

class PmergeMe
{
	std::vector<int>	vec;
	std::deque<int>		deq;

public:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe &operator=(const PmergeMe& other);
	~PmergeMe();

	void sortVec(std::vector<int>& 	other);
	void sortDeque(std::deque<int>& 	other);

	std::vector<int> generateJacobsthal(int n); 
	std::vector<int> getInsertionOrder(int n);
};

#endif