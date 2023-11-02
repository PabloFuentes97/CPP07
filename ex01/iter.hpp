#pragma once
#ifndef	ITER_HPP

#define	ITER_HPP
#include <iostream>

template<typename T, typename func>
void	iter(T &arr, int len, func f)
{
	std::srand(time(NULL));
	int	num = std::rand() % 5;
	for (int i = 0; i < len; i++)
		f(arr[i]);
}

#endif