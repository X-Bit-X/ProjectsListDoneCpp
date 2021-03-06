// Find Cost of Tile to Cover W x H Floor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

//Found in "CustomLibrary"
#include <Input.h>

int main()
{
	std::cout << "Enter width for the floor plan." << std::endl;
	const int width = getConsoleInput<int>();

	std::cout << "Enter height for the floor plan." << std::endl;
	const int height = getConsoleInput<int>();

	std::cout << "Enter cost per tile for the floor plan." << std::endl;
	const double cost = getConsoleInput<double>();

	std::cout << "This will cost you " << width * height * cost << "." << std::endl;

	getchar();
    return 0;
}

