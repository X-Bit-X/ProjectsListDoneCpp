// Credit Card Validator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>
#include <vector>


int main()
{
	std::cout << "Enter your credit card number." << std::endl;
	std::string number;
	std::getline(std::cin, number);

	std::vector<short> cleanNum;
	for (auto &val : number)
		if ([val] { for (char i = '0'; i <= '9'; i++) if (val == i) return true; return false; }())
			cleanNum.push_back(val - '0');

	short result = 0;
	for (short i = 0; i < cleanNum.size(); i++)
	{
		if (i % 2)
		{
			cleanNum[i] *= 2;
			if (cleanNum[i] > 9)
				cleanNum[i] = cleanNum[i] % 10 + cleanNum[i] / 10;
		}
		result += cleanNum[i];
	}

	std::cout << (!(result % 10) ? "The card is valid." : "The card is not valid.") << std::endl;

	getchar();
    return 0;
}

