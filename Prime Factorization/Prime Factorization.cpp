// Prime Factorization.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

//Found in "CustomLibrary"
#include <Input.h>

constexpr bool isPrime(const unsigned long long &input);

int main()
{
	//Get Input
	std::cout << "Input Number to Factorize." << std::endl;
	unsigned long long input = getConsoleInput<unsigned long long>();

	//Prime Factorization Algorithm
	bool oddNum;
	for (unsigned long long i = 4; input != 1; i += 2)
	{
		oddNum = false;
		if (i == 4)
			i = 2;
		if (isPrime(i) && input % i == 0)
		{
			input /= i;
			std::cout << i << " ";
			i = 2;
			oddNum = true;
		}
		if (!oddNum && i == 2)
			i = 1;
	}
	std::cout << std::endl;

	getchar();
    return 0;
}

constexpr bool isPrime(const unsigned long long &input)
{
	for (unsigned long long i = 2; i <= input / 2; i++)
		if (input % i == 0)
			return false;

	return true;
}