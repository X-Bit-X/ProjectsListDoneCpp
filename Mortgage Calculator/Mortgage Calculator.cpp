// Mortgage Calculator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

//Found in "CustomLibrary"
#include <Input.h>

int main()
{
	std::cout << "Enter the duration of loan. (in months)" << std::endl;
	const int duration = getConsoleInput<int>();

	std::cout << "Enter the annual interest rate." << std::endl;
	const double interest = getConsoleInput<double>();

	std::cout << "Enter the loan amount." << std::endl;
	const double loan = getConsoleInput<double>();

	std::cout << "Do you wish for a (d)daily, (w)weekly, (m)monthly or (y)yearly payment rate" << std::endl;
	char payRate = 0;
	while (payRate != 'd' && payRate != 'w' && payRate != 'm' && payRate != 'y')
		payRate = getConsoleInput<char>();

	const double monthlyPay = loan * (interest / 12 * std::pow(1 + interest / 12, duration)) / (std::pow(1 + interest / 12, duration) - 1);
	switch (payRate)
	{
	case 'd': std::cout << "Daily payment: "	<< monthlyPay / 30	<< std::endl; break;
	case 'w': std::cout << "Weekly payment: "	<< monthlyPay / 4	<< std::endl; break;
	case 'm': std::cout << "Monthly payment: "	<< monthlyPay		<< std::endl; break;
	case 'y': std::cout << "Yearly payment: "	<< monthlyPay * 12	<< std::endl; break;
	}


	getchar();
    return 0;
}

