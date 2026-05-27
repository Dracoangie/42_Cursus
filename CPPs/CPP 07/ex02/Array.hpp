/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 14:00:17 by angnavar          #+#    #+#             */
/*   Updated: 2026/05/27 13:02:48 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdlib.h>

template <typename T>
class Array
{
private:
	T* _array;
	size_t _size;
public:

	Array() : _array(NULL), _size(0) {}
	Array(unsigned int n) : _array(new T[n]()), _size(n) {}
	Array(const Array& other) : _array(new T[other._size]()), _size(other._size)
	{
		for (size_t i = 0; i < _size; ++i)
			_array[i] = other._array[i];
	}
	Array& operator=(const Array& other)
	{
		if (this != &other)
		{
			delete[] _array;
			_size = other._size;
			_array = new T[_size]();
			for (size_t i = 0; i < _size; ++i)
				_array[i] = other._array[i];
		}
		return *this;
	}
	~Array() { delete[] _array; }

	T& operator[](unsigned int index)
	{
		if (index >= _size)
			throw std::out_of_range("Index out of bounds");
		return _array[index];
	}

	const T& operator[](unsigned int index) const
	{
		if (index >= _size)
			throw std::out_of_range("Index out of bounds");
		return _array[index];
	}

	unsigned int size() const { return _size; }
};

#endif
