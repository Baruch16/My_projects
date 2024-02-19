#include <ostream>

class Rational
{
private:
    int numerator;
    int denominator;
public : 
    Rational();
    Rational(int n);
    Rational(int n, int d);
    Rational(const Rational &fraction);
    Rational &operator=(const Rational &fraction);
    void print()const;
    float get_value()const;
    
    Rational operator+(const Rational &fraction) const;
    Rational operator-(const Rational &fraction) const;
    Rational operator*(const Rational &fraction) const;
    Rational operator/(const Rational &fraction) const;
    Rational operator+=(const Rational& fraction) const;
    Rational operator-=(const Rational& fraction) const;
    Rational operator*=(const Rational& fraction)const;
    Rational operator/=(const Rational& fraction)const;
    int get_numerator() const;
    int get_denominator() const;
    int GCD(int x,int y) const;
    bool operator==(const Rational& fraction) const;
    bool operator>=(const Rational& fraction) const;
    bool operator<=(const Rational& fraction) const;
    bool operator!=(const Rational& fraction) const;
    bool operator<(const Rational& fraction) const;
    bool operator>(const Rational& fraction) const;
    
    
};
 std::ostream& operator<<(std::ostream& os, Rational r);
