// Unit Converter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <string>
#include <array>

#include "UnitConvertison.h"

//in "CustomLibrary"
#include <Error.h>
#include <Input.h>

struct UnitTypes
{
	const std::string s_name;
	Type s_type;

	UnitTypes(const std::string &name, const Type &type)
		: s_name{ name }, s_type{ type } {}
};

int main()
{
	const std::array<std::string, 7> dataTypes = { "Currency", "Area", "Length", "Mass", "Time", "Temperature", "Volume" };

	std::vector<UnitTypes> data({ 
		UnitTypes(dataTypes[0], Type({ 1, 1.17, 0.00014, 7.45, 80.45, 130.07 },{ "Euro", "Dollar", "Bitcoin", "Krone", "Rupee", "Yen" })), 
		UnitTypes(dataTypes[1], Type({ 1, 2.59, 2.59e+6, 259, 2.788e+7, 640 },{ "SquareMile", "SquareKilometre", "SquareMetre", "Hectare", "SquareFoot", "Acre" })),
		UnitTypes(dataTypes[2], Type({ 1, 1.61, 1609.34, 63360, 5280, 160934 },{ "Mile", "Kilometre", "Metre", "Inch", "Foot", "Centimetre" })),
		UnitTypes(dataTypes[3], Type({ 1, 1000, 1e+6, 2204.62, 35274, 1e+9 },{ "Tonne", "Kilogram", "Gram", "Pound", "Ounce", "Milligram" })),
		UnitTypes(dataTypes[4], Type({ 1, 365, 52.1429, 8760, 525600, 3.1536e+7 },{ "Year", "Day", "Week", "Hour", "Minute", "Second" })),
		UnitTypes(dataTypes[5], Type({ 1, -272.15, -457.87 },{ "Kelvin", "Celsius", "Fahrenheit" })),
		UnitTypes(dataTypes[6], Type({ 1, 264.172, 1000, 1e+6, 4166.67, 67628 },{ "CubicMetre", "Gallon", "Litre", "Millilitre", "Cup", "Tablespoon" })) });

	std::cout << "Welcome to the simple Unit Converter.\nEnter what type of unit you want to convert." << std::endl;
	std::string type = getStringInput(dataTypes.data(), dataTypes.size());

	for (auto &val : data)
		if (val.s_name == type)
		{
			std::cout << "Enter original value and type then enter target type." << std::endl;
			const Unit fromType(Unit(getStringInput(val.s_type.listTypes().data(), val.s_type.listTypes().size()), getConsoleInput<double>()));
			std::cout << val.s_type.convert(fromType, getStringInput(val.s_type.listTypes().data(), val.s_type.listTypes().size())) << std::endl;
		}


	getchar();
    return 0;
}