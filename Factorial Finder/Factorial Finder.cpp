// Factorial Finder.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>
#include <array>

#include <Input.h>

void loopFactFinder(const unsigned long long &input);
const double recursiveFactFinder(unsigned long long num);

int main()
{
	std::cout << "Which method do you prefer?" << std::endl;
	const std::string mode = getStringInput(std::array<std::string, 2>({ "Recursive", "Loop" }).data(), 2);

	std::cout << "Enter a number." << std::endl;
	const double input = getConsoleInput<unsigned long long>();

	if (mode == "Recursive")
		std::cout << recursiveFactFinder(input) << std::endl;
	else
		loopFactFinder(input);


	getchar();
    return 0;
}

void loopFactFinder(const unsigned long long &input)
{
	std::cout << [input] { unsigned long long y = input;  for (short i = 1; i < input; i++) y *= i; return input > 0 ? y : 1; }() << std::endl;
}

const double recursiveFactFinder(unsigned long long num)
{
	return num == 1 ? 1 : num * recursiveFactFinder(num - 1);
}