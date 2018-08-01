// Tax Calculator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

#include <Input.h>


int main()
{
	std::cout << "Enter the price of the item and the tax rate(%)." << std::endl;
	const double cost = getConsoleInput<double>();
	const double tax = getConsoleInput<double>();

	std::cout << "The total cost is " << cost + cost * tax / 100 << "." << std::endl;


	getchar();
    return 0;
}

