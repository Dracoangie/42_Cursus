/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 13:25:04 by angnavar          #+#    #+#             */
/*   Updated: 2026/05/20 11:30:45 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <stdexcept>
#include <vector>
class Span
{
	std::vector<int> numbers;
	unsigned int maxSize;
public:
	Span(unsigned int n);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();
	
	void addNumber(int num);
	int shortestSpan() const;
	int longestSpan() const;

	template <typename Iter>
	void addRange(Iter begin, Iter end)
	{
		if (numbers.size() + std::distance(begin, end) > maxSize)
			throw std::runtime_error("Span is full");
		numbers.insert(numbers.end(), begin, end);
	}
};


#endif