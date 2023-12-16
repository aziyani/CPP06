/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    ScalarConverter.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziyani <aziyani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 15:23:22 by aziyani           #+#    #+#             */
/*   Updated: 2023/12/15 10:56:36 by aziyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
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
    static void convert(const std::string& literal);
};

#endif