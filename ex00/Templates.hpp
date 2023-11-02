#pragma once
#ifndef TEMPLATES_HPP
#define TEMPLATES_HPP

template<typename T>
void	swap(T &a, T &b)
{
	T swap;

	swap = a;
	a = b;
	b = swap;
}

template<typename T>
const T & min(T const &a, T const &b)
{
	if (a < b)
		return (a);
	return (b);
}

template<typename T>
const T & max(T const &a, T const &b)
{
	if (a > b)
		return (a);
	return (b);
}

#endif