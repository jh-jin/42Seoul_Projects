#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdio>

bool isChar(t_data *data)
{
	return data->_str.length() == 1 && !std::isdigit(data->_str[0]);
}

void init_data(t_data *data, std::string literal)
{
	data->_str = literal;
	data->_double = isChar(data) ? static_cast<double>(data->_str[0]) : std::strtod(data->_str.c_str(), NULL);
}

void printChar(t_data *data)
{
	char c = static_cast<char>(data->_double);
	double d = static_cast<double>(c);

	std::cout << "char: ";
	if (c > 0 ? floor(data->_double) == d : ceil(data->_double) == d)
	{
		if (std::isprint(c))
			std::cout << '\'' << c << '\'' << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	else
		std::cout << "impossible" << std::endl;
}

void printInt(t_data *data)
{
	int i = static_cast<int>(data->_double);
	double d = static_cast<double>(i);

	std::cout << "int: ";
	if (i > 0 ? floor(data->_double) == d : ceil(data->_double) == d)
		std::cout << i << std::endl;
	else
		std::cout << "impossible" << std::endl;
}

void printFloat(t_data *data)
{
	float f = static_cast<float>(data->_double);

	std::cout << "float: ";
	if (isinf(f) && !isinf(data->_double))
		std::cout << "impossible" << std::endl;
	else if (isinf(f) && f > 0)
		std::cout << "+inff" << std::endl;
	else
		printf("%.1ff\n", f);
}

void printDouble(t_data *data)
{
	std::cout << "double: ";
	if (isinf(data->_double) && data->_double > 0)
		std::cout << "+";
	printf("%.1lf\n", data->_double);
}

void ScalarConverter::convert(const std::string &literal)
{
	t_data data;

	init_data(&data, literal);
	printChar(&data);
	printInt(&data);
	printFloat(&data);
	printDouble(&data);
}