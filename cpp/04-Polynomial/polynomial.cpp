#include "polynomial.hpp"
#include <iostream>

Poly::Polynomial::Polynomial() 
:degree(0)
,m_coef(DS::Rational_array(1))
 {}

Poly::Polynomial::Polynomial(int d) 
:degree(d)
,m_coef(DS::Rational_array(d+1))
{}


Poly::Polynomial::Polynomial(const DS::Rational_array &a) 
:degree(a.get_size()-1)
,m_coef(a)
{}


Poly::Polynomial::Polynomial(const Polynomial &other) 
:degree(other.degree)
, m_coef(other.m_coef) {}

Poly::Polynomial& Poly::Polynomial::operator=(const Polynomial &other) 
{
    if (this != &other)
    {
        degree = other.degree;
        m_coef = other.m_coef;
    }
    return *this;
}

Poly::Polynomial::~Polynomial() {}

int Poly::Polynomial::get_degree() const
{
    return degree;
}

Rational Poly::Polynomial::get_m_coefficient(int index) const
{
    if (index < 0 || index > degree)
    {
        std::cout << "Error: index out of range" << std::endl;
        exit(1);
    }
    return m_coef.get_element(index);
}

void Poly::Polynomial::set_m_coefficient(int index, Rational value)
{
    if (index < 0 || index > degree)
    {
        std::cout << "Error: index out of range" << std::endl;
        exit(1);
    }
    m_coef.set_element(index, value);
}


Poly::Polynomial Poly::Polynomial::operator+(const Polynomial &other) const
{
    
    Polynomial result=(get_degree()>other.get_degree()?*this:other);
    for (int i = 0; i <= get_degree() && i<=other.get_degree(); i++)
    {
        result.set_m_coefficient(i, get_m_coefficient(i) + other.get_m_coefficient(i));
    }
    return result;
}

Poly::Polynomial Poly::Polynomial::operator-(const Polynomial &other) const
{
     Polynomial result=(get_degree()>other.get_degree()?*this:other);
    
    for (int i = 0; i <= get_degree() && i<=other.get_degree(); i++)
    {
        result.set_m_coefficient(i, get_m_coefficient(i) - other.get_m_coefficient(i));
    }
    return result;
}

Poly::Polynomial Poly::Polynomial::operator*(const Polynomial &other) const
{
    int new_degree = degree + other.degree;
    Polynomial result(new_degree);
    for (int i = 0; i <= degree; i++)
    {
        for (int j = 0; j <= other.degree; j++)
        {
            result.set_m_coefficient(i+j, result.get_m_coefficient(i+j) + (get_m_coefficient(i) * other.get_m_coefficient(j)));
        }
    }
    return result;
}

Poly::Polynomial Poly::Polynomial::operator/( const Polynomial &other ) const
{
    if (degree < other.degree)
    {
        std::cout << "Error: cannot divide polynomials of different degree" << std::endl;
        exit(1);
    }
    else
    {
        Polynomial copy(*this); // create a copy of the original polynomial
        int iterator_degree=degree;
        int new_degree = degree - other.degree +1;
        Polynomial result(new_degree);
        Polynomial quotient(iterator_degree);
        while (iterator_degree >= other.degree)
        {
            result.set_m_coefficient(iterator_degree - other.degree, copy.get_m_coefficient(iterator_degree) / other.get_m_coefficient(other.degree));
            for (int i = 0; i <= other.degree; i++)
            {
                quotient.set_m_coefficient(i, result.get_m_coefficient(iterator_degree - other.degree) * other.get_m_coefficient(i));
            }
            for (int i = 0; i <= iterator_degree; i++)
            {
                copy.set_m_coefficient(i, copy.get_m_coefficient(i) - quotient.get_m_coefficient(i));
            }
            iterator_degree--;
        }
        if(result!=0){
        	std::cout<<"Error:reminder"<<"\n";
        	exit(0);
        }
        return result;
    }

}

bool Poly::Polynomial::operator==(const Polynomial &other) const
{
    if (degree != other.degree)
    {
        return false;
    }
    for (int i = 0; i <= degree; i++)
    {
        if (get_m_coefficient(i) != other.get_m_coefficient(i))
        {
            return false;
        }
    }
    return true;
}

bool Poly::Polynomial::operator!=(const Polynomial &other) const
{
    return !(*this == other);
}

Rational Poly::Polynomial::evaluate(Rational x) const
{
    Rational result = 0;
    for (int i = degree; i >= 0; i--)
    {
        result = result * x + get_m_coefficient(i);
    }
    return result;
}

std::ostream& operator<<(std::ostream& os, const Poly::Polynomial &p)
{	
    
    for (int i =0; i<= p.get_degree(); i++) {
        if (p.get_m_coefficient(i) != 0) {
            os << p.get_m_coefficient(i) << "x^" << i ;
            if(i<p.get_degree()){
            	std::cout<< " + ";
            }
        }
    }
    return os;
}

