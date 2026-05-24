/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 20:41:40 by angnavar          #+#    #+#             */
/*   Updated: 2026/05/20 11:31:37 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main()
{
    try
    {
        // Test del ejemplo del subject
        std::cout << "=== Subject test ===" << std::endl;

        Span sp(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest : " << sp.longestSpan() << std::endl;


        std::cout << "\n=== Large test ===" << std::endl;

        const int SIZE = 10000;

        Span big(SIZE);

        std::srand(std::time(NULL));

        std::vector<int> numbers;

        for (int i = 0; i < SIZE; i++)
            numbers.push_back(std::rand());

        // usar el método por rango
        big.addRange(numbers.begin(), numbers.end());

        std::cout << "Stored: " << SIZE << " numbers" << std::endl;
        std::cout << "Shortest: " << big.shortestSpan() << std::endl;
        std::cout << "Longest : " << big.longestSpan() << std::endl;


        std::cout << "\n=== Exception test ===" << std::endl;

        try
        {
            big.addNumber(42);
        }
        catch(const std::exception& e)
        {
            std::cout << "Expected exception: "
                      << e.what() << std::endl;
        }


        std::cout << "\n=== Not enough numbers ===" << std::endl;

        try
        {
            Span test(5);

            test.addNumber(1);

            std::cout << test.shortestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cout << "Expected exception: "
                      << e.what() << std::endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: "
                  << e.what()
                  << std::endl;
    }

    return 0;
}

