#ifndef CUSTOMINPUT
#define CUSTOMINPUT

#include <limits>
#include <ios>
#include <string>

template<typename T>
constexpr const T getConsoleInput()
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

#endif // !CUSTOMINPUT

