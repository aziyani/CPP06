/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziyani <aziyani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 15:23:22 by aziyani           #+#    #+#             */
/*   Updated: 2023/12/18 11:37:22 by aziyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
#include <iomanip>
#include <sstream>

enum {
CHAR = 'c',
INT = 'i',
DOUBLE = 'd',
FLOAT = 'f' ,
NOT = 'x'
};

class  ScalarConverter
{
public:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& obj);
    ~ScalarConverter();
    ScalarConverter &operator=(const ScalarConverter& obj);
    static void convert(const std::string& literal);
};

#endif