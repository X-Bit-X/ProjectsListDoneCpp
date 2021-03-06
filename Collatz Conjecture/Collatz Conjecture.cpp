// Collatz Conjecture.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

#include <Input.h>


constexpr unsigned long long collatzConjecture(unsigned long long n)
{
	unsigned long long i = 0;
	for (; n > 1; i++)
		n = n & 1 ? n * 3 + 1 : n / 2;
	return i;
}

int main()
{
	std::cout << "Enter a number." << std::endl;
	std::cout << collatzConjecture(getConsoleInput<unsigned long long>()) << std::endl;


	getchar();
    return 0;
}