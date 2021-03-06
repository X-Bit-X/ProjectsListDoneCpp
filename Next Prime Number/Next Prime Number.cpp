// Next Prime Number.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <limits>

constexpr bool isPrime(const unsigned long long &input);

int main()
{
	std::cout << "Press enter for next prime number." << std::endl;

	for (unsigned long long i = 0; i < std::numeric_limits<unsigned long long>::max(); i++)
		if (isPrime(i))
		{
			std::cout << i;
			getchar();
		}

	return 0;
}

constexpr bool isPrime(const unsigned long long &input)
{
	for (unsigned long long i = 2; i <= input / 2; i++)
		if (input % i == 0)
			return false;

	return true;
}