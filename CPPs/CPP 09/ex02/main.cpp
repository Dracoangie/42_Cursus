/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 20:41:40 by angnavar          #+#    #+#             */
/*   Updated: 2026/05/25 15:15:04 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool validNum(char* str) {

    for (int i = 0; str[i]; i++) {
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}

int	main(int ac, char **av) {

	if (ac < 2) {

		std::cerr << "Error" << std::endl;
		return 1;
	}

	std::vector<int> vec;
	std::deque<int> deq;

	for (int i = 1; i < ac; i++)
	{
    	if (!validNum(av[i])) {
        	std::cerr << "Error" << std::endl;
        	return 1;
    	}

		int num = atoi(av[i]);

		if (num < 0) {
			std::cerr << "Error: negative value" << std::endl;
			return 1;
		}
		vec.push_back(num);
		deq.push_back(num);
	}

	PmergeMe pmergeMe;

	
	std::cout << "Before: " << std::endl;
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;

	clock_t start = clock();
	pmergeMe.sortVec(vec);
	clock_t end = clock();
	double timeVec = (double)(end - start) / CLOCKS_PER_SEC * 1000000;

	start = clock();
	pmergeMe.sortDeque(deq);
	end = clock();
	double timeDeq = (double)(end - start) / CLOCKS_PER_SEC * 1000000;

	std::cout << "After: ";
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;

	std::cout << "Time to process a range of " << vec.size()
		<< " elements with std::vector : " << timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size()
		<< " elements with std::deque  : " << timeDeq << " us" << std::endl;

    return 0;
}

