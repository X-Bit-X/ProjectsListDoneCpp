// Fibonacci Sequence.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

constexpr unsigned long long calFibonacci(const short &limit);

int main()
{
	//Take Input
	std::cout << "Which digit of the Fibonacci Sequence be generated? (Limit 93)" << std::endl;
	short limit;
	while (true)
	{
		std::cin >> limit;
		if (std::cin.fail() || limit <= 0 || limit > 93)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid." << std::endl;
		}
		else
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			break;
		}
	}

	//Calculate Fibonacci
	std::cout << calFibonacci(limit) << std::endl;


	getchar();
    return 0;
}

constexpr unsigned long long calFibonacci(const short &limit)
{
	//Return Invalid Numbers
	if (limit == 1)
		return 0;
	else if (limit == 2)
		return 1;

	//Fibonacci Algorithm
	unsigned long long sequence[] = { 0, 1, 0 };
	for (short n = 1; true;)
	{
		sequence[2] = sequence[0] + sequence[1];
		n++;
		if (n == limit)
			return sequence[2];
		sequence[0] = sequence[2] + sequence[1];
		n++;
		if (n == limit)
			return sequence[0];
		sequence[1] = sequence[0] + sequence[2];
		n++;
		if (n == limit)
			return sequence[1];
	}
}