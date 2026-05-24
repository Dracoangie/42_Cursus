/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 20:41:40 by angnavar          #+#    #+#             */
/*   Updated: 2026/05/24 20:58:57 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main(int argc, char **argv) {

    if (argc != 2) {
        std::cerr << "Error: usage: ./RPN \"expression\"" << std::endl;
        return 1;
    }

    Rpn rpn;
    rpn.calculation(argv[1]);

    return 0;
}

