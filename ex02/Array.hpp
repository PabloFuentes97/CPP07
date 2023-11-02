#pragma once
#ifndef ARRAY_HPP

#define ARRAY_HPP
#include <exception>
#include <string>
#include <iostream>

template <typename T>
class Array
{
	private:
		T 				*_array;
		size_t			_size;
		void 			copyArray(Array const &src);
	public:
		Array();
		Array(int size);
		Array(const Array &src);
		~Array();
		Array 	&operator=(Array const &rhs);
		T 		&operator[](int i);
		class	IndexOutOfRangeExcept : public std::exception
		{
			public:
				virtual const char *what() const throw ();
		};
		size_t	size(void) const;
		T 		*getArray(void) const;
};

template <typename T>
std::ostream &operator<<(std::ostream &o, const Array<T> &src);

#include "Array.tpp"
#endif