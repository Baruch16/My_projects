#include <iostream>
#include "rational_array.hpp"

namespace Poly{

class Polynomial
{

   
public:
    explicit Polynomial();
    Polynomial(int d);
    explicit Polynomial(const DS::Rational_array &a);
    Polynomial(const Polynomial &other);
    Polynomial& operator=(const Polynomial &other);
    ~Polynomial();

    int get_degree() const;
    Rational get_m_coefficient(int index) const;
    void set_m_coefficient(int index, Rational value);
   
    
    // arithmetic operators
    Polynomial operator+(const Polynomial &other) const;
    Polynomial operator-(const Polynomial &other) const;
    Polynomial operator*(const Polynomial &other) const;
    Polynomial operator/(const Polynomial &other) const ;

    // relational operators
    bool operator==(const Polynomial &other) const;
    bool operator!=(const Polynomial &other) const;
   
    // evaluation
    Rational evaluate(Rational x) const;
    
  private:
   int degree;
   DS::Rational_array m_coef;
    
};
}

std::ostream& operator<<(std::ostream& os, const Poly::Polynomial &p);

