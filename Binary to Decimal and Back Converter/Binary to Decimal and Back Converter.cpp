// Binary to Decimal and Back Converter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>

#include <Input.h>

void toBinary(const unsigned long long &dec);
void toDecimal();

int main()
{
	char choice;
	do
	{
		std::cout << "To (d)decimal or to (b)Binary?" << std::endl;
		choice = getConsoleInput<char>();
	} while (choice != 'd' && choice != 'b');

	if (choice == 'd')
		toDecimal();
	else
	{
		std::cout << "Enter decimal number:" << std::endl;
		toBinary(getConsoleInput<unsigned long long>());
	}
		

	getchar();
    return 0;
}

void toDecimal()
{
	//Input
	std::cout << "Enter binary number:" << std::endl;
	std::string binNum;
	std::getline(std::cin, binNum);

	//Error Check
	bool error = false;
	int lengthError = 0;
	std::string cleanBinNum;
	for (auto &val : binNum)
		if (val == '0' || val == '1')
		{
			if (val == '1' && !error)
				error = true;
			if (error)
			{
				lengthError++;
				if (lengthError > 63)
				{
					std::cerr << "Too high." << std::endl;
					return;
				}
			}
			cleanBinNum.push_back(std::move(val));
		}

	//Binary Algorithm
	unsigned long long decNum = 0;
	for (short i = 0; i < cleanBinNum.length(); i++)
		switch (cleanBinNum[i])
		{
		case '0': break;
		case '1': decNum += std::pow(2, cleanBinNum.length() - i - 1); break;
		}

	std::cout << decNum << std::endl;
}

//Recurrsive
void toBinary(const unsigned long long &dec)
{
	if (dec / 2 != 0)
		toBinary(dec / 2);
	std::cout << dec % 2;
}