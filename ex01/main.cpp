/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziyani <aziyani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:14:22 by aziyani           #+#    #+#             */
/*   Updated: 2023/12/18 13:18:16 by aziyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(int __unused argc, char const __unused **argv)
{
    Serializer serializer;

    Data data;

    data.FirstName = "ayoub";

    uintptr_t uni = serializer.serialize(&data);
    Data *new_data = serializer.deserialize(uni);

    std::cout << new_data->FirstName << std::endl;

    return 0;
}