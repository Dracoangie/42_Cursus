/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 11:11:41 by angnavar          #+#    #+#             */
/*   Updated: 2026/05/20 11:30:38 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : maxSize(n) {}
Span::Span(const Span& other) : numbers(other.numbers), maxSize(other.maxSize) {}
Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		numbers = other.numbers;
		maxSize = other.maxSize;
	}
	return *this;
}
Span::~Span() {}

void Span::addNumber(int num)
{
	if (numbers.size() >= maxSize)
		throw std::runtime_error("Span is full");
	numbers.push_back(num);
}

int Span::shortestSpan() const
{
	if (numbers.size() < 2)
		throw std::runtime_error("Not enough numbers to find a span");
	std::vector<int> sorted(numbers);
	std::sort(sorted.begin(), sorted.end());
	int minSpan = sorted[1] - sorted[0];
	for (size_t i = 1; i < sorted.size(); ++i)
	{
		int span = sorted[i] - sorted[i - 1];
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
}

int Span::longestSpan() const
{
	if (numbers.size() < 2)
		throw std::runtime_error("Not enough numbers to find a span");
	int min = *std::min_element(numbers.begin(), numbers.end());
	int max = *std::max_element(numbers.begin(), numbers.end());
	return max - min;
}