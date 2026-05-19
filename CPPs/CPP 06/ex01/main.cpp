/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 20:41:40 by angnavar          #+#    #+#             */
/*   Updated: 2026/05/19 12:37:34 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"
#include <iostream>

int main()
{
    Data data;

    data.name = "Angela";
    data.age = 42;
    data.value = 4.2f;

    std::cout << "Original object:" << std::endl;
    std::cout << "Address: " << &data << std::endl;
    std::cout << "Name: " << data.name << std::endl;
    std::cout << "Age: " << data.age << std::endl;
    std::cout << "Value: " << data.value << std::endl;

    uintptr_t raw = Serializer::serialize(&data);

    std::cout << "\nSerialized value:" << std::endl;
    std::cout << raw << std::endl;

    Data* restored = Serializer::deserialize(raw);

    std::cout << "\nDeserialized object:" << std::endl;
    std::cout << "Address: " << restored << std::endl;
    std::cout << "Name: " << restored->name << std::endl;
    std::cout << "Age: " << restored->age << std::endl;
    std::cout << "Value: " << restored->value << std::endl;

    std::cout << "\nPointer comparison: ";

    if (&data == restored)
        std::cout << "SUCCESS " << std::endl;
    else
        std::cout << "FAIL" << std::endl;

    return (0);
}
