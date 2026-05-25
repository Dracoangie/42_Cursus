#include "PmergeMe.hpp"
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 22:19:04 by angnavar          #+#    #+#             */
/*   Updated: 2026/05/24 22:21:07 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe& other)
{vec = other.vec; deq = other.deq;}
PmergeMe &PmergeMe::operator=(const PmergeMe& other) 
{
	vec = other.vec; deq = other.deq; 
	return *this;
}
PmergeMe::~PmergeMe(){}

void PmergeMe::sortVec(std::vector<int>& other)
{
	std::vector<int>	big;
	std::vector<int>	little;
	int 				rest = -1;

	if (other.size() <= 1)
		return;

	for (size_t i = 0; i + 1 < other.size(); i += 2) {
		
		if (other[i] > other[i + 1])
		{
			big.push_back(other[i]);
			little.push_back(other[i + 1]);
		}
		else
		{
			big.push_back(other[i + 1]);
			little.push_back(other[i]);
		}
	}

	if (other.size() % 2 != 0)
		rest = other[other.size() - 1];

	std::vector<std::pair<int, int> >	pairs;
	for (size_t i = 0; i < big.size(); i++)
		pairs.push_back(std::make_pair(big[i], little[i]));

	sortVec(big);

	little.clear();
	for (size_t i = 0; i < big.size(); i++)
	{
		for (size_t j = 0; j < pairs.size(); j++)
		{
			if (pairs[j].first == big[i])
			{
				little.push_back(pairs[j].second);
				break;
			}
		}
	}
	big.insert(big.begin(), little[0]);
	std::vector<int> order = getInsertionOrder(little.size());

	for (size_t i = 0; i < order.size(); i++)
	{
		int idx = order[i];

		std::vector<int>::iterator pos = std::lower_bound(big.begin(), big.end(), little[idx]);
		big.insert(pos, little[idx]);
	}

	if (rest > -1)
	{
		std::vector<int>::iterator	pos = std::lower_bound(big.begin(), big.end(), rest);
		big.insert(pos, rest);
	}

	other = big;
}

void PmergeMe::sortDeque(std::deque<int>&  other)
{
	std::deque<int>	big;
	std::deque<int>	little;
	int 				rest = -1;

	if (other.size() <= 1)
		return;

	for (size_t i = 0; i + 1 < other.size(); i += 2) {
		
		if (other[i] > other[i + 1])
		{
			big.push_back(other[i]);
			little.push_back(other[i + 1]);
		}
		else
		{
			big.push_back(other[i + 1]);
			little.push_back(other[i]);
		}
	}

	if (other.size() % 2 != 0)
		rest = other[other.size() - 1];

	std::deque<std::pair<int, int> >	pairs;
	for (size_t i = 0; i < big.size(); i++)
		pairs.push_back(std::make_pair(big[i], little[i]));

	sortDeque(big);

	little.clear();
	for (size_t i = 0; i < big.size(); i++)
	{
		for (size_t j = 0; j < pairs.size(); j++)
		{
			if (pairs[j].first == big[i])
			{
				little.push_back(pairs[j].second);
				break;
			}
		}
	}
	big.insert(big.begin(), little[0]);
	std::vector<int> order = getInsertionOrder(little.size());

	for (size_t i = 0; i < order.size(); i++)
	{
		int idx = order[i];

		std::deque<int>::iterator pos = std::lower_bound(big.begin(), big.end(), little[idx]);
		big.insert(pos, little[idx]);
	}

	if (rest > -1)
	{
		std::deque<int>::iterator	pos = std::lower_bound(big.begin(), big.end(), rest);
		big.insert(pos, rest);
	}

	other = big;
}

std::vector<int> PmergeMe::generateJacobsthal(int n) {

    std::vector<int> jacob;
    jacob.push_back(0);
    jacob.push_back(1);

    while (jacob.back() < n) {
        size_t size = jacob.size();
        int next = jacob[size - 1] + 2 * jacob[size - 2];
        jacob.push_back(next);
    }
    return jacob;
}

std::vector<int> PmergeMe::getInsertionOrder(int n) {

    std::vector<int> jacob = generateJacobsthal(n);
    std::vector<int> order;

    for (size_t i = 2; i < jacob.size(); i++)
	{
        int end = jacob[i];
        if (end > n) end = n;
        int start = jacob[i - 1];

        for (int j = end; j > start; j--) {
            order.push_back(j - 1);
        }
    }
    return order;
}
