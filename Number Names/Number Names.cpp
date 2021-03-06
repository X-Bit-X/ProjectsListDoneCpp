// Number Names.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <array>
#include <cmath>
#include <string>
#include <sstream>

//From "Custom Library"
#include <Input.h>


int main()
{
	double input;
	do
	{
		std::cout << "Enter a number to be translated to english. (5 precision)" << std::endl;
		input = getConsoleInput<double>();
	} while (input > 999999999);

	//Negative check
	if (input < 0)
	{
		std::cout << "negative ";
		input = std::fabs(input);
	}

	const std::array<std::string, 10> numbers({ "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" });
	const std::array<std::string, 8> teners({ "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninty" });
	const std::array<std::string, 9> teens({ "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" });
	const std::array<std::string, 3> prefix({ "", "thousand", "million" });

	//Break up digits
	std::string digits(std::to_string(input));
	std::string point;
	for (int i = digits.find('.') + 1; i < digits.length(); i++)
		point.push_back(digits[i]);
	digits.erase(digits.find('.'), digits.length() - 1);

	//For above point
	if (input == 0)
		std::cout << numbers.back();
	for (char i = 0; i < digits.size(); i++)
		if (digits[i] != '0')
			switch ((digits.size() - i - 1) % 3)
			{
			case 2: std::cout << numbers[digits[i] - '0'] << " hundred "; break;
			case 1: std::cout << (digits[i] > '1' ? teners[digits[i] - '0' - 2] + (digits[i + 1] != '0' ? "-" : "") : teens[digits[++i] - '0']); break;
			case 0: std::cout << numbers[digits[i] - '0'] << " " << prefix[(digits.size() - i - 1) / 3] << (i == digits.size() - 1 ? "" : " "); break;
			}
	//For below point
	if ([&point] { for (const auto &val : point) if (val != '0') return true; return false; }())
		for (short i = 0; i < point.size() - [&point] { for (char i = point.length() - 1; true; i--) if (point[i - 1] != '0' || i <= 0) return point.length() - i; }(); i++)
			std::cout << (i == 0 ? "point " : "") << numbers[point[i] - '0'] << " ";
	std::cout << std::endl;

	getchar();
    return 0;
}

//Note: I could improve this by directly getting an input of type string, but right now I am too lazy to do it. This will make the decimals have "infinite" precision.