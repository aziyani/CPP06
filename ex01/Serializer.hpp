/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziyani <aziyani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:15:30 by aziyani           #+#    #+#             */
/*   Updated: 2023/12/20 17:47:32 by aziyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>

typedef struct
{
    std::string FirstName;
    std::string LastName;
    int age;
    int height;
    int weight;
    int number;
}   Data;

class Serializer
{
    public:
        Serializer();
        Serializer(const Serializer& obj);
        Serializer &operator=(const Serializer& obj);
        ~Serializer();

        uintptr_t serialize(Data* ptr); // convert data pionter to uintptr (unsigned long int)
        Data* deserialize(uintptr_t raw); // convert uinptr to data pointer
        
};

#endif