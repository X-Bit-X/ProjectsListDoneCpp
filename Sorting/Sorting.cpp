// Sorting.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <type_traits>
#include <algorithm>
#include <array>
#include <vector>

#include <Input.h>
#include <RandomNumber.h>


template<typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
constexpr T* bubbleSort(T *arr, unsigned int length)
{
	for (; length != 0; length--)
		for (unsigned int i = 0; i < length - 1; i++)
			if (arr[i] > arr[i + 1])
				std::swap(arr[i], arr[i + 1]);
	return arr;
}

template<typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>				//Iterative not recursive
constexpr T* mergeSort(T *arr, const unsigned int &length)
{
	const unsigned int check = [&length]() constexpr { for (unsigned int i = 1; true; i *= 2) if (i >= length) return i; }();
	std::vector<T> temp(length);
	for (unsigned int arrSize = 2; arrSize <= check; arrSize *= 2)
	{
		for (unsigned int arrStart = 0, iter = 0; arrStart < length; arrStart += arrSize)
			for (unsigned int a = arrStart, b = arrStart + arrSize / 2; (a < arrStart + arrSize / 2 && a < length) || (b < arrStart + arrSize && b < length); iter++)
				temp[iter] = std::move(arr[b < length && b < arrStart + arrSize && a < arrStart + arrSize / 2 ? arr[a] >= arr[b] ? b++ : a++ : a < arrStart + arrSize / 2 ? a++ : b++]);
		for (unsigned int i = 0; i < length; i++)
			arr[i] = std::move(temp[i]);
	}
	return arr;
}

int main()
{
	RandomGenerator<Generator::Linear> randNum;

	std::array<int, 7> test;
	for (auto &val : test)
		val = randNum.randNumber<int>(0, 100);
	mergeSort(test.data(), test.size());
	for (const auto &val : test)
		std::cout << val << "\n";
	std::cout << std::endl;

	std::array<double, 7> test2;
	for (auto &val : test2)
		val = randNum.randNumber<int>(0, 100);
	bubbleSort(test2.data(), test2.size());
	for (const auto &val : test2)
		std::cout << val << "\n";
	std::cout << std::endl;


	getchar();
    return 0;
}