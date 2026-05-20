/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 20:41:40 by angnavar          #+#    #+#             */
/*   Updated: 2026/05/20 10:57:54 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "easyfind.hpp"
#include <vector>

int main(void)
{
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	try
	{		
		std::vector<int>::iterator it = easyfind(vec, 2);
		std::cout << "Value found: " << *it << std::endl;
	}
	catch (const std::exception& e) { std::cerr << e.what() << std::endl; }
	try
	{		
		std::vector<int>::iterator it = easyfind(vec, 4);
		std::cout << "Value found: " << *it << std::endl;
	}
	catch (const std::exception& e) { std::cerr << e.what() << std::endl; }
    return 0;
}
