// Find e to the Nth Digit.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <limits>
#include <string>


int main()
{
	//Take Input
	std::cout << "Till which digit should e be generated? (Limit 100)" << std::endl;
	short limit;
	while (true)
	{
		std::cin >> limit;
		if (std::cin.fail() || limit < 0 || limit > 100)
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

	//Generate e
	const std::string e("2.7182818284590452353602874713526624977572470936999595749669676277240766303535475945713821785251664274");
	for (char i = 0; i < limit + 2; i++) //limit + 2.
		std::cout << e[i];
	std::cout << std::endl;


	getchar();
	return 0;
}

