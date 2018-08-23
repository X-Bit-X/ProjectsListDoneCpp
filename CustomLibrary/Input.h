#ifndef CUSTOMINPUT
#define CUSTOMINPUT

#include <limits>
#include <iostream>
#include <string>
#include <type_traits>
#include <vector>

template<typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
constexpr T getConsoleInput()
{
	T input;
	while (true)
	{
		std::cin >> input;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cerr << "Invalid." << std::endl;
		}
		else
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return input;
		}
	}
}

//They stay because of old code
const std::wstring getStringInput(const std::wstring *list, const short &length)
{
	std::wstring type;
	while (true)
	{
		std::getline(std::wcin, type);
		if (type == L"help")
			for (short i = 0; i < length; i++)
				std::wcout << "\"" << list[i] << "\"\n";
		else if ([&list, &length, &type]() { for (short i = 0; i < length; i++) if (list[i] == type) return true; return false; }())
			return type;
		else
			std::wcerr << L"Invalid." << std::endl;
	}
	return type;
}
const std::string getStringInput(const std::string *list, const short &length)
{
	std::string type;
	while (true)
	{
		std::getline(std::cin, type);
		if (type == "help")
			for (short i = 0; i < length; i++)
				std::cout << "\"" << list[i] << "\"\n";
		else if ([&list, &length, &type]() { for (short i = 0; i < length; i++) if (list[i] == type) return true; return false; }())
			return type;
		else
			std::cerr << "Invalid." << std::endl;
	}
	return type;
}

//New improved
const std::string getStringInput(const std::vector<std::string> &list)
{
	std::string type;
	while (true)
	{
		std::getline(std::cin, type);
		if (type == "help")
			for (short i = 0; i < list.size(); i++)
				std::cout << "\"" << list[i] << "\"\n";
		else if ([&list, &type]() { for (const auto &val : list) if (val == type) return true; return false; }())
			return type;
		else
			std::cerr << "Invalid." << std::endl;
	}
	return type;
}
const std::wstring getStringInput(const std::vector<std::wstring> &list)
{
	std::wstring type;
	while (true)
	{
		std::getline(std::wcin, type);
		if (type == L"help")
			for (short i = 0; i < list.size(); i++)
				std::wcout << L"\"" << list[i] << L"\"\n";
		else if ([&list, &type]() { for (const auto &val : list) if (val == type) return true; return false; }())
			return type;
		else
			std::wcerr << L"Invalid." << std::endl;
	}
	return type;
}

#endif // !CUSTOMINPUT

