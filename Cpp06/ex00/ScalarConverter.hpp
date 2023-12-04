#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <string>

typedef struct s_data
{
	std::string _str;
	double _double;

} t_data;

class ScalarConverter
{
public:
	static void convert(const std::string &literal);
};

#endif