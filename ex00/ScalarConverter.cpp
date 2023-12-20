/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziyani <aziyani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 15:23:15 by aziyani           #+#    #+#             */
/*   Updated: 2023/12/20 15:34:50 by aziyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& obj)
{
	*this = obj;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter& __unused obj)
{
	return *this;
}

ScalarConverter::~ScalarConverter()
{
}

int checkType(const std::string& literal){
	int type = 0, flag = 0;
	char *p;
	std::strtod(literal.c_str(), &p); // convet from pointer to double
	if (!std::isdigit(literal.c_str()[0]) && literal.length() == 1){
		return CHAR;
	}
	size_t i = 0;
	if (literal[i] == '+' || literal[i] == '-')
		i++;
	for (;literal[i];i++){
		if ((i == (literal.length() - 1)) && literal[i] == 'f'){
			if (type != NOT)
				return FLOAT;
			return NOT;
		}
		else if (literal[i] == '.' && flag == 0){
			type = DOUBLE;
			flag = 1;
		}
		else if (!std::isdigit(literal[i]))
			type = NOT;
			
	}
	if (type == 0)
		return INT;
	return type;
}


void CtoInt(std::string literal)
{
	std::stringstream stream(literal);
	char *p;

	int value = static_cast<int>(std::strtod(literal.c_str(), &p));
	char c = static_cast<char>(value);
	float f = static_cast<float>(value);
	double d = static_cast<double>(value);
	if (value >= 32 && value <= 126)
		std::cout << "char: " << "'" << c << "'"<< std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << value << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(2) << f << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(2) << d << std::endl;
}

void CtoFloat(std::string literal)
{
	std::stringstream stream(literal);
	float value = static_cast<float>(std::strtod(literal.c_str(), NULL));
	char c = static_cast<char>(value);
	int i = static_cast<int>(value);
	double d = static_cast<double>(value);
	if (value >= 32 && value <= 126)
		std::cout << "char: " << "'" << c << "'"<< std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(2) << value << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(2) << d << std::endl;
}

void CtoDouble(std::string literal)
{
	std::stringstream stream(literal);
	double value = static_cast<double>(std::strtod(literal.c_str(), NULL));
	char c = static_cast<char>(value);
	int i = static_cast<int>(value);
	float f = static_cast<float>(value);
	if (value >= 32 && value <= 126)
		std::cout << "char: " << "'" << c << "'"<< std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(2) << f << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(2) << value << std::endl;
}

void	CtoChar(std::string literal)
{
	int n = 0;

	double d = static_cast<double>(literal[n]);
	int i = static_cast<int>(literal[n]);
	float f = static_cast<float>(literal[n]);
	if (literal[n] >= 32 && literal[n] < 127)
{
		std::cout << "char: " << "'" << literal << "'"<< std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(2) << f << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(2) << d << std::endl;
	}
	else
		std::cout << "This character are not printable" << std::endl;
}

void ScalarConverter::convert(const std::string& literal)
{
	int type = checkType(literal);
	if (type == NOT)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
	
	if (type == CHAR)
	    CtoChar(literal);
	else if (type == INT)
		CtoInt(literal); // check if literal can be stored in int (using sstream) -> store it in a int using strtod
	else if (type == FLOAT)
	    CtoFloat(literal); // check if literal can be stored in int (using sstream) -> store it in a int using strtod
	else if (type == DOUBLE)
	    CtoDouble(literal); // check if literal can be stored in int (using sstream) -> store it in a int using strtod
}