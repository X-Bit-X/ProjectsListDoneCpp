#ifndef RANDOMGEN
#define RANDOMGEN

#include <random>
#include <typeinfo>
#include <type_traits>

#include "Error.h"

//Seperated
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

	RandomGenerator() : m_gen{ rd() } {}

	template<typename Type, typename = typename std::enable_if<std::is_arithmetic<Type>::value, Type>::type>
	constexpr Type randNumber(const Type &min, const Type &max)
	{
		if (min >= max)
			throw Error("RandomGenerator -> min is larger or equal to max.");

		return typeid(Type) == typeid(double) || typeid(Type) == typeid(float) ? std::uniform_real_distribution<>(min, max)(m_gen) : std::uniform_int_distribution<>(min, max)(m_gen);
	}

private:

	T m_gen;
	std::random_device rd;
};

#endif // !RANDOMGEN
