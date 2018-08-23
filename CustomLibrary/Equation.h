
//Warning: This has one crappy error check. Use only clean data for this.

#ifndef EQUATION
#define EQUATION

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <cmath>

#include "Error.h"

class Equation
{
public:

	Equation() = delete;
	Equation(const Equation &) = delete;
	Equation(Equation &&) = delete;

	static double solve(const std::string &input)
	{
		//Parse
		std::vector<std::string> equation;
		for (unsigned int i = 0; i < input.size(); i++)
		{
			static std::string parBuf;

			if (input[i] == '-' || input[i] == '+')
				parBuf.push_back(input[i]);
			if (input[i] == '(' || input[i] == ')')
				equation.push_back(std::move(parBuf) + input[i]);

			for (const auto &func : checkers)
				if (func(input[i]))
				{
					parBuf.push_back(input[i]);
					if (!func(input[i + 1]))
						equation.push_back(std::move(parBuf));
				}
		}

		//Find all bracket pairs
		std::vector<std::array<unsigned int, 2>> brackets;
		for (unsigned int i = 0; i < equation.size(); i++)
			if (equation[i] == "(" || equation[i] == "+(" || equation[i] == "-(")
				brackets.push_back({ i, 0 });
			else if (equation[i] == ")")
				brackets.at([&brackets] { for (int i = brackets.size() - 1; i >= 0; i--) if (brackets[i][1] == 0) return i; throw Error("Front brackets missing."); }())[1] = i;

		//Sort order of calculation
		std::sort(brackets.begin(), brackets.end(), [](const std::array<unsigned int, 2> &x, const std::array<unsigned int, 2> &y) constexpr { return x[1] - x[0] < y[1] - y[0]; });
		if (!brackets.empty() && brackets.front()[1] == 0)
			throw Error("Back brackets missing.");

		//Calculate
		for (unsigned int i = 0; i < brackets.size(); i++)
		{
			equation[brackets[i][0]] = std::to_string((equation[brackets[i][0]] == "-(" ? -1 : 1) * evaluate(std::vector<std::string>(&equation[brackets[i][0] + 1], &equation[brackets[i][1]])));
			std::fill(equation.begin() + brackets[i][0] + 1, equation.begin() + brackets[i][1] + 1, "");
		}
		std::remove(equation.begin(), equation.end(), "");

		return evaluate(equation);
	}

private:

	static constexpr std::array<bool(*)(const char &), 3> checkers = {
		[](const char &val) constexpr { for (char i = '0'; i <= '9'; i++) if (i == val || val == '.') return true; return false; },
		[](const char &val) constexpr { for (char i = 'a'; i <= 'z'; i++) if (i == val) return true; return false; },
		[](const char &val) constexpr { return '*' == val || '/' == val; } };

	static double evaluate(std::vector<std::string> equation)
	{
		struct Pair
		{
			const std::string s_name; const double s_val; double(*s_func)(double);
			Pair(const std::string &name, const double &val, double(*func)(double) = nullptr)
				: s_name{ name }, s_val{ val }, s_func{ func } {}
		};

		//Step 1: Constant
		for (unsigned int i = 0; i < equation.size(); i++)
			for (const auto &val : { Pair("pi", std::acos(-1)), Pair("e", std::exp(1)) })
				if (equation[i] == val.s_name || equation[i] == '+' + val.s_name || equation[i] == '-' + val.s_name)
					if (equation[i].front() != '-')
						equation[i] = std::to_string(val.s_val);
					else
						equation[i] = std::to_string(-val.s_val);

		//Step 2: Modifier
		for (unsigned int i = 0; i < equation.size(); i++)
		{
			auto check = [&equation, &i](const Pair &val, double(*func)(const double &))
			{
				if (equation[i] == val.s_name || equation[i] == '-' + val.s_name || equation[i] == '+' + val.s_name)
				{
					if (equation[i].front() != '-')
						equation[i] = std::to_string(val.s_func(func(std::stod(equation[i + 1]))));
					else
						equation[i] = std::to_string(-val.s_func(func(std::stod(equation[i + 1]))));
					equation.erase(equation.begin() + i + 1, equation.begin() + i + 2);
				}
			};

			for (const auto &val : { Pair("sin", 0, std::sin), Pair("cos", 0, std::cos), Pair("tan", 0, std::tan), Pair("asin", 0, std::asin), Pair("acos", 0, std::acos), Pair("atan", 0, std::atan) })
				check(val, [](const double &num) { return num / 180 * std::acos(-1); });
			for (const auto &val : { Pair("fact", 0, [](double x) { if (std::round(x) != x || x < 0) throw Error("Number has a point or it's negative."); return [&x] { double y = x;  for (short i = 1; i < x; i++) y *= i; return x > 0 ? y : 1; }(); }),
				Pair("log", 0, std::log), Pair("sqrt", 0, std::sqrt) })
				check(val, [](const double &num) constexpr { return num; });
		}

		//Step 3: Joiner
		for (unsigned int i = 0; i < equation.size(); i++)
			if (equation[i] == "*" || equation[i] == "/" || equation[i] == "mod" || equation[i] == "root" || equation[i] == "pow")
			{
				if (equation[i] == "*")
					equation[--i] = std::to_string(std::stod(equation[i - 1]) * std::stod(equation[i + 1]));
				else if (equation[i] == "/")
					equation[--i] = std::to_string(std::stod(equation[i - 1]) / std::stod(equation[i + 1]));
				else if (equation[i] == "mod")
					equation[--i] = std::to_string((int)std::round(std::stod(equation[i - 1])) % (int)std::round(std::stod(equation[i + 1])));
				else if (equation[i] == "root")
					equation[--i] = std::to_string(std::pow(std::stod(equation[i - 1]), 1 / std::stod(equation[i + 1])));
				else if (equation[i] == "pow")
					equation[--i] = std::to_string(std::pow(std::stod(equation[i - 1]), std::stod(equation[i + 1])));
				if (equation[i + 1] == "/" && (equation[i + 2] == "0.000000" || equation[i + 2] == "0"))
					throw Error("Equation has a divide by zero.");
				equation.erase(equation.begin() + i + 1, equation.begin() + i + 3);
			}

		//Step 4: Sum
		double result = 0;
		for (const auto &val : equation)
			if (val != "")
				result += std::stod(val);

		return result;
	}
};
#endif // !EQUATION