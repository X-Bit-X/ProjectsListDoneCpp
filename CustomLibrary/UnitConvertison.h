#ifndef UNITCONVERSION
#define UNITCONVERSION

#include <Error.h>
#include <vector>

struct Unit
{
	const std::string s_type;
	const double s_value;

	Unit(const std::string &type, const double &Value)
		: s_type{ type }, s_value{ Value } {}
};

class Type
{

public:

	Type() {}

	Type(const std::vector<double> &values, const std::vector<std::string> &types)
			: m_values{ values }, m_types{ types } 
	{
		if (values.size() != types.size())
			throw Error("Values and types aren't the same length.");
	}

	Type(const Type &ty)
		: m_types{ ty.m_types }, m_values{ ty.m_values } {}

	Type(Type &&ty)
		: m_values{ std::move(ty.m_values) }, m_types{ std::move(ty.m_types) } {}

	const double convert(const Unit &from, const std::string &to) const
	{
		auto find = [this](const std::string &target) { for (short i = 0; i < m_types.size(); i++) if (m_types[i] == target) return i; throw Error("Type non-existant"); };
		const short iFrom = find(from.s_type);
		const short iTo = find(to);

		return from.s_value / m_values[iFrom] * m_values[iTo];
	}
	
	const std::vector<double>& listValues() const { return m_values; }
	const std::vector<std::string>& listTypes() const { return m_types; }

	Type& operator=(const Type &ty)
	{
		m_values = ty.m_values;
		m_types = ty.m_types;
		return *this;
	}
	Type& operator=(Type &&ty)
	{
		m_values = std::move(ty.m_values);
		m_types = std::move(ty.m_types);
		return *this;
	}
	
private:

	std::vector<double> m_values;
	std::vector<std::string> m_types;

};

namespace DefaultType
{
	extern const Type distance({ 1, 1.61, 1609.34, 63360, 5280, 160934 }, { "Mile", "Kilometre", "Metre", "Inch", "Foot", "Centimetre" });
}

#endif // !UNITCONVERSION
