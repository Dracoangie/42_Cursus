/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 13:25:04 by angnavar          #+#    #+#             */
/*   Updated: 2026/05/24 21:11:10 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <list>
#include <string>
#include <iostream>
#include <sstream>


class Rpn {

    private:
        std::stack<long, std::list<long> > _stack;

    public:
        Rpn();
        Rpn(Rpn const &copy);
        Rpn &operator=(Rpn const &copy);
        ~Rpn();

        void calculation(std::string const &expression);
};

#endif