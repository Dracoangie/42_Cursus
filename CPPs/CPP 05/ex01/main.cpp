/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 20:41:40 by angnavar          #+#    #+#             */
/*   Updated: 2025/12/04 13:42:49 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    std::cout << "===== TEST 1: Creación válida =====" << std::endl;
    try {
        Bureaucrat b1("Alice", 42);
        std::cout << b1 << std::endl;

        Bureaucrat b2("Bob", 1);
        std::cout << b2 << std::endl;

        Bureaucrat b3("Charlie", 150);
        std::cout << b3 << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 2: Creación con grados inválidos =====" << std::endl;
    try {
        Bureaucrat bad1("TooHigh", 0);
    }
    catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat bad2("TooLow", 151);
    }
    catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 3: Incrementar y decrementar =====" << std::endl;
    try {
        Bureaucrat b("David", 5);
        std::cout << b << std::endl;

        std::cout << "Incrementando..." << std::endl;
        b.increment();
        std::cout << b << std::endl;

        std::cout << "Decrementando..." << std::endl;
        b.decrement();
        std::cout << b << std::endl;

        std::cout << "Forzando un error (incrementar desde 1)..." << std::endl;
        Bureaucrat top("Edward", 1);
        std::cout << top << std::endl;
        std::cout << "Incrementando..." << std::endl;
        top.increment();
    }
    catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 4: Decremento fuera de rango =====" << std::endl;
    try {
        Bureaucrat low("Frank", 150);
        std::cout << low << std::endl;
        std::cout << "Decrementando..." << std::endl;
        low.decrement();
    }
    catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
