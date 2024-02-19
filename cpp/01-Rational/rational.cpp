#include "rational.hpp"
#include "iostream"

Rational::Rational()
:numerator(0)
,denominator(1)
{}
Rational::Rational(int n)
	:numerator(n)
	,denominator(1)
{}

Rational::Rational(int n, int d)
:numerator(n)
,denominator(d)
{}
	

Rational::Rational(const Rational& fraction)//call constructor
    :numerator(fraction.numerator)
    ,denominator(fraction.denominator)
{}

Rational& Rational::operator=(const Rational& fraction)//create an object operator
{
    numerator=fraction.numerator;
    denominator=fraction.denominator;
    return *this;   
}

void Rational::print()const // print the Rational value
{
    std::cout <<"the fraction is" << (double)numerator/denominator<<"\n";
}

float Rational::get_value()const
{
    return (double)numerator/denominator;
}

Rational Rational::operator+(const Rational& fraction)const
{
    Rational res(0,0);
    res.numerator=(this->numerator*fraction.denominator)+(this->denominator*fraction.numerator);
    res.denominator=this->denominator*fraction.denominator;
    return res;
}
Rational Rational::operator+=(const Rational& fraction)const
{ 
    Rational res(0,0);
    res.numerator=(this->numerator*fraction.denominator)+(this->denominator*fraction.numerator);
    res.denominator=this->denominator*fraction.denominator;
    return res;
}

Rational Rational::operator-(const Rational& fraction)const
{
    Rational res(0,0);
    res.numerator=(this->numerator*fraction.denominator)-(this->denominator*fraction.numerator);
    res.denominator=this->denominator*fraction.denominator;
    return res;
}

Rational Rational::operator-=(const Rational& fraction)const
{
    Rational res(0,0);
    res.numerator=(this->numerator*fraction.denominator)-(this->denominator*fraction.numerator);
    res.denominator=this->denominator*fraction.denominator;
    return res;
}

Rational Rational::operator*(const Rational& fraction)const
{
    Rational res(0,0);
    res.numerator=fraction.numerator*this->numerator;
    res.denominator=this->denominator*fraction.denominator;
    return res;
}

Rational Rational::operator*=(const Rational& fraction)const
{
    Rational res(0,0);
    res.numerator=fraction.numerator*this->numerator;
    res.denominator=this->denominator*fraction.denominator;
    return res;
}
Rational Rational::operator/(const Rational& fraction)const
{
    Rational res(0,0);
    
     if (this->denominator==0) {	
		std::cout<<"Error denominator=0" << std::endl;
		exit(1);
	}
    res.numerator=this->numerator*fraction.denominator;
    res.denominator=this->denominator*fraction.numerator;
    return res;
}

Rational Rational::operator/=(const Rational& fraction)const
{	
    Rational res(0,0);
    if (this->denominator==0) {	
		std::cout<<"Error denominator=0" << std::endl;
		exit(1);
	}
    res.numerator=this->numerator*fraction.denominator;
    res.denominator=this->denominator*fraction.numerator;
    return res;
}

bool Rational::operator==(const Rational& fraction)const
{
	return ((double)numerator/denominator)==((double)fraction.numerator/fraction.denominator);
}

bool Rational::operator>=(const Rational& fraction)const
{
	return ((double)numerator/denominator)>=((double)fraction.numerator/fraction.denominator);
}

bool Rational::operator<=(const Rational& fraction)const
{
	return ((double)numerator/denominator)<=((double)fraction.numerator/fraction.denominator);
}

bool Rational::operator<(const Rational& fraction)const
{
	return ((double)numerator/denominator)<((double)fraction.numerator/fraction.denominator);
}

bool Rational::operator>(const Rational& fraction)const
{
	return ((double)numerator/denominator)>((double)fraction.numerator/fraction.denominator);
}

bool Rational::operator!=(const Rational& fraction)const
{
	return ((double)numerator/denominator)!=((double)fraction.numerator/fraction.denominator);
}
int Rational::get_numerator()const{

	return numerator;
}

int Rational::get_denominator()const{

	return denominator;
}

std::ostream& operator<<(std::ostream& os, Rational r){
	int reducer=r.GCD(r.get_numerator(),r.get_denominator());
	int new_numer=r.get_numerator()/reducer;
	int new_denom=r.get_denominator()/reducer;
	if(new_denom==1){
		 os<<new_numer;
	}
	
	else{
 	os<< new_numer<<"/" << new_denom;
 	}
 	return os;
 	
 }
 	
int Rational::GCD(int x, int y)const{ 

	return (y == 0) ? x : GCD(y, x % y);
 }
