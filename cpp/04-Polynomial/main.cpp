#include "polynomial.hpp"
#include <iostream>

int main()
{
    // Create a polynomial of degree 3
    Poly::Polynomial p1(3);
    p1.set_m_coefficient(3, Rational(1, 1)); // x^3
    p1.set_m_coefficient(2, Rational(2, 1)); // x^2
    p1.set_m_coefficient(1, Rational(3, 1)); // x
    p1.set_m_coefficient(0, Rational(4, 1)); // constant term
    std::cout << "Polynomial 1: ";
    std::cout<<p1<<"\n";
    
    
    
    // Create a polynomial of degree 2
    Poly::Polynomial p2(2);
    p2.set_m_coefficient(2, Rational(1, 1)); // x^2
    p2.set_m_coefficient(1, Rational(2, 1)); // x
    p2.set_m_coefficient(0, Rational(3, 1)); // constant term
    std::cout << "Polynomial 2: ";
    std::cout<<p2<<"\n";
    
    DS::Rational_array r(4);
    r.set_element(0,1);
    r.set_element(1,2);
    r.set_element(2,3);
    r.set_element(3,4);
    Poly::Polynomial p3(r);
    std::cout<<p3<<"\n";
   
    
    
    // Perform arithmetic operations
    std::cout << "Polynomial 1 + Polynomial 2: ";
    std::cout<<(p1+p2)<<"\n";
    std::cout << "Polynomial 1 - Polynomial 2: ";
    std::cout<<(p1 - p2)<<"\n";
    std::cout << "Polynomial 1 * Polynomial 2: ";
    std::cout<<(p1 * p2)<<"\n";
    std::cout << "Polynomial 1 / Polynomial 2: ";
    //std::cout<<(p1 / p2)<<"\n";
    
     
    // Evaluate the polynomial at a specific value
    Rational x(5, 1);
    Rational y(4,3);
    std::cout << "Polynomial 1 evaluated at " << y.get_value() << ": " << p1.evaluate(y) << std::endl;
    
    if(p1.evaluate(x)==p1.evaluate(y))
    	std::cout<<"correct"<<"\n";
    else
    	std::cout<<"wrong"<<"\n";
    
   
}

