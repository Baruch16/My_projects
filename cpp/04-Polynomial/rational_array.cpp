#include "rational_array.hpp"
#include <iostream>
#include <cassert>

DS::Rational_array::Rational_array() 
: size(0)
, data(nullptr) {}

DS::Rational_array::Rational_array(int s) : size(s)
{
    data = new Rational[size];
}

DS::Rational_array::Rational_array(const Rational_array &other)
{	

    size = other.size;
    data = new Rational[size];
    assert(data!=0);
    for (int i = 0; i < size; i++)
    {
        data[i] = other.data[i];
    }
}

DS::Rational_array& DS::Rational_array::operator=(const Rational_array &other)
{
    if (this == &other)
    {
        return *this;
    }
    delete[] data;
    size = other.size;
    data = new Rational[size];
    assert(data!=0);
    for (int i = 0; i < size; i++)
    {
        data[i] = other.data[i];
    }
    return *this;
}

DS::Rational_array::~Rational_array()
{
    delete[] data;
}

int DS::Rational_array::get_size() const
{
    return size;
}

Rational DS::Rational_array::get_element(int index) const
{
    return data[index];
}

void DS::Rational_array::set_element(int index, Rational value)
{
    data[index] = value;
}

void DS::Rational_array::print() const
{
    for (int i = 0; i < size; i++)
    {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}


