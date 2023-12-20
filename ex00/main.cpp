/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziyani <aziyani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:30:32 by aziyani           #+#    #+#             */
/*   Updated: 2023/12/20 13:05:46 by aziyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// static

int main(int ac, char **av){
    ScalarConverter a;

    if (ac > 1)
        a.convert(av[1]);
    
    return(0);
}