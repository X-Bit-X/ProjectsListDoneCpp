#ifndef RANDOMNUMBER
#define RANDOMNUMBER

#include <random>
#include <typeinfo>
#include <type_traits>

#include "Error.h"

class RandomNumber
{
private:

	//Engine Construction
	std::random_device rd;
	std::mt19937 mersenne;

public:

	RandomNumber() : mersenne{ rd() } {}

	template<typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
	constexpr T RandNumber(const T &min, const T &max)
	{
		if (min >= max)
			throw Error("RandomNumber -> min is larger or equal to max.");

		if (typeid(T) == typeid(double) || typeid(T) == typeid(float))
		{
			std::uniform_real_distribution<> die(min, max);
			return die(mersenne);
		}
		else
		{
			std::uniform_int_distribution<> die(min, max);
			return die(mersenne);
		}
	}
};
#endif // !RANDOMNUMBER
