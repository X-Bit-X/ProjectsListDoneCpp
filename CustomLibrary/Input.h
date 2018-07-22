#ifndef CUSTOMINPUT
#define CUSTOMINPUT

#include <limits>
#include <ios>

template<typename T>
const T getConsoleInput()
{
	T input;
	while (true)
	{
		std::cin >> input;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid." << std::endl;
		}
		else
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return input;
		}
	}
}

#endif // !CUSTOMINPUT

