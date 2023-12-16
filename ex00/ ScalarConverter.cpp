/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    ScalarConverter.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziyani <aziyani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 15:23:15 by aziyani           #+#    #+#             */
/*   Updated: 2023/12/16 17:44:42 by aziyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <sstream>
#include " ScalarConverter.hpp"

int checkType(const std::string& literal){
	int type = 0, flag = 0;
	if (!std::isdigit(literal.c_str()[0]) && literal.length() == 1){
		return CHAR;
	}
	int i = 0;
	if (literal[i] == '+' || literal[i] == '-')
		i++;
	for (;literal[i];i++){
		if (i == literal.length() - 1 && literal[i] == 'f'){
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
	int realInt;

	if (stream >> realInt)
	{
		int value = static_cast<int>(std::strtod(literal.c_str(), NULL));
		char c = static_cast<char>(value);
		float f = static_cast<float>(value);
		double d = static_cast<double>(value);
		if (value >= 33 && value <= 126)
			std::cout << "char: " << "'" << c << "'"<< std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << value << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(2) << f << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(2) << d << std::endl;
	}
	else 
		std::cerr << "Err" << std::endl;
}

void CtoFloat(std::string literal)
{
	std::stringstream stream(literal);
	int realFloat;

	if (stream >> realFloat)
	{
		float value = static_cast<float>(std::strtod(literal.c_str(), NULL));
		char c = static_cast<char>(value);
		int i = static_cast<int>(value);
		double d = static_cast<double>(value);
		if (value >= 33 && value <= 126)
			std::cout << "char: " << "'" << c << "'"<< std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(2) << value << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(2) << d << std::endl;
	}
	else 
		std::cerr << "Err" << std::endl;
}

void CtoDouble(std::string literal)
{
	std::stringstream stream(literal);
	int realDouble;

	if (stream >> realDouble)
	{
		double value = static_cast<double>(std::strtod(literal.c_str(), NULL));
		char c = static_cast<char>(value);
		int i = static_cast<int>(value);
		float f = static_cast<float>(value);
		if (value >= 33 && value <= 126)
			std::cout << "char: " << "'" << c << "'"<< std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(2) << f << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(2) << value << std::endl;
	}
	else 
		std::cerr << "Err" << std::endl;
}

void ScalarConverter::convert(const std::string& literal)
{
	int type = checkType(literal);
	double value = std::strtod(literal.c_str(), NULL);
	if (type == NOT)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
	
	// else if (type == CHAR)
	//     CtoChar(literal);
	else if (type == INT)
		CtoInt(literal); // check if literal can be stored in int (using sstream) -> store it in a int using strtod
	else if (type == FLOAT)
	    CtoFloat(literal); // check if literal can be stored in int (using sstream) -> store it in a int using strtod
	else if (type == DOUBLE)
	    CtoDouble(literal); // check if literal can be stored in int (using sstream) -> store it in a int using strtod
}