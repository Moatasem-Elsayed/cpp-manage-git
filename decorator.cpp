#include "decorator.hpp"
#include <iostream>
decorator::decorator(/* args */)
{
}

decorator::~decorator()
{
}
void decorator::DisplaySpliiter(std::string value)
{
    std::cout << "---------------------------------" << std::endl;
    std::cout << "-                               -" << std::endl;
    std::cout << "-            " << value << "                   -" << std::endl;
    std::cout << "-                               -" << std::endl;
    std::cout << "---------------------------------" << std::endl;
}