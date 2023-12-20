/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziyani <aziyani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:39:46 by aziyani           #+#    #+#             */
/*   Updated: 2023/12/20 22:25:15 by aziyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"
# include <iostream>

// dynamic

Base * generate(void)
{
	std::srand(time(NULL));
    int rand_;
    Base * base;
    rand_ = rand() % 3;

    if (rand_ == 0)
        base = new A();
    if (rand_ == 1)
        base = new B();
    if (rand_ == 2)
        base = new C();
    return (base);
}

void identify(Base* p)
{
    A *a;
    C *c;
    B *b;
    
    a = dynamic_cast<A*>(p);
    b = dynamic_cast<B*>(p);
    c = dynamic_cast<C*>(p);
    if (a != NULL)
        std::cout << "Object is of type A" << std::endl;
    else if (b != NULL)
        std::cout << "Object is of type B" << std::endl;
    else if (c != NULL)
        std::cout << "Object is of type C" << std::endl;
    else
        std::cout << "Object is of unknown type" << std::endl;
}

void identify(Base& p)
{
    char y = 'x';
    try
    {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        y = 'A';
    }
    catch(const std::exception& e)
    {
    }
    try
    {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        y = 'B';
    }
    catch(const std::exception& e)
    {
    }
    try
    {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        y = 'C';
    }
    catch(const std::exception& e)
    {
    }
    if (y != 'x')
        std::cout << "Object type identified: " << std::endl;
    else
        std::cout << "Object type not identified." << std::endl; 
}

int main()
{
    Base *base = generate();
    identify(base);
    identify(base);
}