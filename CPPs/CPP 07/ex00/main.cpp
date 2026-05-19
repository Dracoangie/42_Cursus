/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 20:41:40 by angnavar          #+#    #+#             */
/*   Updated: 2026/05/19 14:11:35 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include <iostream>
#include <string>
#include "whatever.hpp"

int main(void)
{
    // INT TEST
    int a = 2;
    int b = 3;

    std::cout << "---- INT ----" << std::endl;
    std::cout << "a = " << a << ", b = " << b << std::endl;

    ::swap(a, b);

    std::cout << "after swap:" << std::endl;
    std::cout << "a = " << a << ", b = " << b << std::endl;

    std::cout << "min(a,b) = " << ::min(a,b) << std::endl;
    std::cout << "max(a,b) = " << ::max(a,b) << std::endl;


    // STRING TEST
    std::string c = "chaine1";
    std::string d = "chaine2";

    std::cout << "\n---- STRING ----" << std::endl;
    std::cout << "c = " << c << ", d = " << d << std::endl;

    ::swap(c, d);

    std::cout << "after swap:" << std::endl;
    std::cout << "c = " << c << ", d = " << d << std::endl;

    std::cout << "min(c,d) = " << ::min(c,d) << std::endl;
    std::cout << "max(c,d) = " << ::max(c,d) << std::endl;


    // EQUAL VALUES TEST
    int x = 42;
    int y = 42;

    std::cout << "\n---- EQUAL VALUES ----" << std::endl;

    std::cout << "x = " << x << ", y = " << y << std::endl;

    std::cout << "min(x,y) = " << ::min(x,y) << std::endl;
    std::cout << "max(x,y) = " << ::max(x,y) << std::endl;

    return 0;
}
