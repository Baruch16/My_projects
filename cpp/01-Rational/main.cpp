#include <iostream>
#include "rational.hpp"

int main(){
    Rational a(10, 12);
    Rational b(10,12); 
    Rational c(5);
    Rational d(13,18);
    Rational e = a + b;
    //test the operators
    d.print();
    d = a - b;
    d.print();
    d = a * b;
    d.print();
    d = a / b;
    d.print();
    //test boolean operators
    if (a==b){
    	std::cout<<"a==b\n";
    	}
    if (a!=d){
    	std::cout<<"a!=d\n";
    	}
    if (a>=b){
    	std::cout<<"a>=b\n";
    	}
    if (a<=b){
    	std::cout<<"a<=b\n";
    	}
    if (a<d){
    	std::cout<<"a<d\n";
    	}
    if (a>d){
    	std::cout<<"a>d\n";
    	}
    //test the stream and GCD .
    std::cout<<e<<"\n";
    std::cout<<a.GCD(a.get_numerator(),a.get_denominator())<<"\n";
    
    
}
