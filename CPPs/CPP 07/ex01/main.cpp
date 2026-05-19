/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 20:41:40 by angnavar          #+#    #+#             */
/*   Updated: 2026/05/19 14:21:25 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void printElement(const T& element)
{
    std::cout << element << std::endl;
}

template <typename T>
void incrementElement(T& element)
{
    element++;
}

void toUpperChar(char& c)
{
    if (c >= 'a' && c <= 'z')
        c -= 32;
}

int main(void)
{
    int numbers[] = {1, 2, 3, 4, 5};
    std::string words[] = {"hello", "42", "madrid"};
    char letters[] = {'a', 'b', 'c'};

    std::cout << "---- INT ARRAY ----" << std::endl;
    iter(numbers, 5, printElement<int>);

    std::cout << "\nIncrementing int array..." << std::endl;
    iter(numbers, 5, incrementElement<int>);
    iter(numbers, 5, printElement<int>);

    std::cout << "\n---- STRING ARRAY ----" << std::endl;
    iter(words, 3, printElement<std::string>);

    std::cout << "\n---- CHAR ARRAY ----" << std::endl;
    iter(letters, 3, printElement<char>);

    std::cout << "\nUppercase char array..." << std::endl;
    iter(letters, 3, toUpperChar);
    iter(letters, 3, printElement<char>);

    const int constNumbers[] = {10, 20, 30};

    std::cout << "\n---- CONST INT ARRAY ----" << std::endl;
    iter(constNumbers, 3, printElement<int>);

    return 0;
}