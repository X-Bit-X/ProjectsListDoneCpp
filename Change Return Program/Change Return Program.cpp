// Change Return Program.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <array>

//From "CustomLibrary" folder
#include <Input.h>


int main()
{
	double change;
	do
	{
		std::cout << "Initial cost:" << std::endl;
		const double cost = std::fabs(getConsoleInput<double>());

		std::cout << "Money given:" << std::endl;
		const double given = std::fabs(getConsoleInput<double>());

		change = std::round((given - cost) * 100);
		if (change < 0.0)
			std::cerr << "Not enough money given." << std::endl;
	} 
	while (change < 0.0);
	
	const std::array<int, 15> currency = { 50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5, 2, 1 }; //Euro
	std::array<int, 15> neededChange = { 0 };

	for (char i = 0; i < currency.size(); i++)
		while (change >= currency[i])
		{
			change -= currency[i];
			neededChange[i]++;
		}

	for (char i = currency.size() - 1; i >= 0; i--)
		std::cout << (double)currency[i] / 100 << " Euro: \t" << neededChange[i] << std::endl;


	getchar();
    return 0;
}

