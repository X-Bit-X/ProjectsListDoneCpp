// Alarm Clock.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <thread>
#include <chrono>

//from "CustomLibrary"
#include <Input.h>


int main()
{
	std::cout << "Welcome to the simple alarm clock.\nEnter in how many seconds the alarm will go off." << std::endl;
	unsigned long long time = getConsoleInput<unsigned long long>();

	std::this_thread::sleep_for(std::chrono::seconds(time));
	std::cout << "The alarm went off!" << std::endl;

	for (char i = 0; i < 10; i++)
	{
		std::cout << "\a";
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}


	getchar();
    return 0;
}

