// Coin Flip Simulation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

//From "CustomLibrary"
#include <Input.h>
#include <RandomNumber.h>


int main()
{
	RandomNumber randNum;

	std::cout << "How many times should the coin be flipped?" << std::endl;
	const unsigned long long flip = getConsoleInput<unsigned long long>();

	unsigned long long headTail[2] = { 0 };
	for (unsigned long long i = 1; i <= flip; i++)
	{
		const char theFlip = randNum.RandNumber<char>(0, 1);
		headTail[theFlip]++;
		std::cout << i << "\t" << (theFlip ? "heads" : "tails") << "\t\t heads: " << headTail[0] << "\t tails: " << headTail[1] << "\n";
	}


	getchar();
    return 0;
}

