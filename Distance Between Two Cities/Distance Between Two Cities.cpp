// Distance Between Two Cities.cpp : Defines the entry point for the console application.
//

//I'll try to implement the google maps api to this somehow in the future. For now, I only have a maths function.

#include "stdafx.h"

#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <string>

#include <Input.h>
#include <UnitConvertison.h>


struct Location
{
	const double s_latitude;
	const double s_longitude;
};

const double getDistance(const Location &loc1, const Location &loc2);

int main()
{
	std::cout << "Welcome to the simple distance calculator based on latitude and longitude.\nEnter the latitude and longitude of your start position and then target position." << std::endl;
	
	const Location pos1 = { getConsoleInput<double>(), getConsoleInput<double>() };
	std::cout << std::endl;
	const double d = getDistance(pos1, { getConsoleInput<double>(), getConsoleInput<double>() });

	std::cout << "\nIn which unit should the answer be?" << std::endl;
	std::cout << DefaultType::distance.convert(Unit("Metre", d), getStringInput(DefaultType::distance.listTypes().data(), DefaultType::distance.listTypes().size())) << std::endl;


	getchar();
    return 0;
}

const double getDistance(const Location &loc1, const Location &loc2)
{
	auto toRadians = [](const double &val) { return val * M_PI / 180; };

	//From https://en.wikipedia.org/wiki/Haversine_formula
	return 2 * 6371000 * asin(std::sqrt(std::pow(std::sin(toRadians(loc2.s_latitude - loc1.s_latitude) / 2), 2) + std::cos(toRadians(loc1.s_latitude)) * std::cos(toRadians(loc2.s_latitude)) * std::pow(std::sin(toRadians(loc2.s_longitude - loc1.s_longitude) / 2), 2)));
}