// Sieve of Eratosthenes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <vector>

#include <Input.h>


int main()
{
	std::cout << "Enter a number." << std::endl;
	const unsigned int n = getConsoleInput<unsigned int>();

	std::vector<bool> list(n + 1);
	for (size_t i = 2; i * i <= n; i++)
		if (!list[i])
			for (size_t b = i * 2; b <= n; b += i)
				list[b] = true;

	for (size_t i = 2; i <= n; i++)
		if (!list[i])
			std::cout << i << " ";


	getchar();
    return 0;
}