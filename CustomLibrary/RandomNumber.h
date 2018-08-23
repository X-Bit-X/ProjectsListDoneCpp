#ifndef RANDOMNUMBER
#define RANDOMNUMBER

#include <random>
#include <typeinfo>
#include <type_traits>

#include "Error.h"

//Old
class RandomNumber
{
private:

	std::random_device rd;
	std::mt19937 mersenne;

public:

	RandomNumber() : mersenne{ rd() } {}

	template<typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
	constexpr T randNumber(const T &min, const T &max)
	{
		if (min >= max)
			throw Error("RandomNumber -> min is larger or equal to max.");

		return typeid(T) == typeid(double) || typeid(T) == typeid(float) ? std::uniform_real_distribution<>(min, max)(mersenne) : std::uniform_int_distribution<>(min, max)(mersenne);
	}
};

//New
namespace Generator
{
	using Mersenne = std::mt19937;
	using Linear = std::minstd_rand;
	using SubtractWithCarry = std::ranlux24_base;
}

//Generator::
template<class T, typename = typename std::enable_if<std::is_same<Generator::Mersenne, T>::value || std::is_same<Generator::Linear, T>::value || std::is_same<Generator::SubtractWithCarry, T>::value>::type>
class RandomGenerator
{

public:

	RandomGenerator() : m_gen{ std::random_device() } {}

	template<typename Type, typename = typename std::enable_if<std::is_arithmetic<Type>::value, Type>::type>
	constexpr Type randNumber(const Type &min, const Type &max)
	{
		if (min >= max)
			throw Error("RandomGenerator -> min is larger or equal to max.");

		return typeid(Type) == typeid(double) || typeid(Type) == typeid(float) ? std::uniform_real_distribution<>(min, max)(m_gen) : std::uniform_int_distribution<>(min, max)(m_gen);
	}

private:

	T m_gen;
};

#endif // !RANDOMNUMBER