// Complex Number Algebra.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <array>
#include <string>

#include <Input.h>

//Simple Comlex class (not efficient)
class Complex
{

public:

	constexpr Complex(const double &real, const double &imaginary)
		: m_real{ real }, m_imaginary{ imaginary } {}

	constexpr Complex operator+(const Complex &x) const
	{
		return Complex(m_real + x.m_real, m_imaginary + x.m_imaginary);
	}

	constexpr Complex operator-(const Complex &x) const
	{
		return Complex(m_real - x.m_real, m_imaginary + -x.m_imaginary);
	}

	constexpr Complex operator*(const Complex &x) const
	{
		return Complex(m_real * x.m_real + -m_imaginary * x.m_imaginary, m_real * x.m_imaginary + m_imaginary * x.m_real);
	}

	constexpr Complex operator/(const Complex &x) const
	{
		const Complex conjugate(x.m_real, -x.m_imaginary);
		const Complex bottom(x * conjugate);
		const Complex top(*this * conjugate);

		return Complex(top.m_real / bottom.m_real, top.m_imaginary / bottom.m_real);
	}

	constexpr Complex inverse() const
	{
		return Complex(1, 0) / *this;
	}

	constexpr Complex operator-() const
	{
		return Complex(-m_real, -m_imaginary);
	}

	friend std::ostream& operator<<(std::ostream &write, const Complex &com)
	{
		return write << com.m_real << std::showpos << com.m_imaginary << "i" << std::noshowpos;
	}

private:

	double m_real;
	double m_imaginary;

};


int main()
{
	std::cout << "Enter the first complex(real then imaginary) then the operator(help) then if needed the second complex." << std::endl;
	double temp = getConsoleInput<double>();
	const Complex x(temp, getConsoleInput<double>());
	std::cout << std::endl;

	const std::string _operator_(getStringInput({ "+", "-", "*", "/", "inverse", "negate" }));
	
	if (_operator_ == "inverse")
		std::cout << x.inverse() << std::endl;
	else if (_operator_ == "negate")
		std::cout << -x << std::endl;
	else
	{
		std::cout << std::endl;
		temp = getConsoleInput<double>();
		Complex y(temp, getConsoleInput<double>());
		if (_operator_ == "+")
			std::cout << x + y << std::endl;
		else if (_operator_ == "-")
			std::cout << x - y << std::endl;
		else if (_operator_ == "*")
			std::cout << x * y << std::endl;
		else if (_operator_ == "/")
			std::cout << x / y << std::endl;
	}


	getchar();
    return 0;
}

