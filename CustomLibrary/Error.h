#ifndef MYERROR
#define MYERROR

#include <exception>
#include <string>

class Error : public std::exception
{
private:
	std::string m_error;
public:
	Error(const std::string &msg)
		: m_error{ msg } {}
	const char* what() const noexcept { return m_error.c_str(); }
};

#endif // !MYERROR
