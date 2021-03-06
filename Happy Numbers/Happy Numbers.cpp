// Happy Numbers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <cmath>


int main()
{
	std::cout << "Here are the first 8 happy numbers." << std::endl;

	for (int i = 0, check = 0; check < 8; i++)
		for (int b = 0, test = i; b < 1000; b++)
		{
			int sum = 0;
			for (;test > 0; test /= 10)
				sum += std::pow(test % 10, 2);
			test = std::move(sum);
			if (test == 1)
			{
				std::cout << i << ' ';
				check++;
				break;
			}
		}
	std::cout << std::endl;

	getchar();
    return 0;
}

