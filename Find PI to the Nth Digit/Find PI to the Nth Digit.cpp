// Find PI to the Nth Digit.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <limits>
#include <string>


int main()
{
	//Take Input
	std::cout << "Till which digit should Pi be generated? (Limit 100)" << std::endl;
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

	//Generate Pi
	const std::string pi("3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679");
	for (char i = 0; i < limit + 2; i++) //limit + 3.
		std::cout << pi[i];
	std::cout << std::endl;


	getchar();
    return 0;
}

