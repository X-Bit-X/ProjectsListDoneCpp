// Fast Exponentiation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

#include <Input.h>


double power(unsigned long long x, unsigned long long n)
{
	double result = 1;
	for (; n; x *= x, n /= 2)
		if (n & 1)
		{
			result *= x;
			n--;
		}
	return result;
}

int main()
{
	std::cout << "Enter the base then the exponent." << std::endl;
	unsigned long long &&x = getConsoleInput<unsigned long long>();
	std::cout << power(x, getConsoleInput<unsigned long long>());


	getchar();
    return 0;
}