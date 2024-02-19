#include <iostream>
#include "arrstack.hpp"

int main()
{	
	//check the default constructor case
	Stack s4;
	s4.push(9);
	std::cout<<s4.pop()<<std::endl;
	
	//check the push and pop
	Stack s1(3);
	s1.push(1);
	s1.pop();
	
	//check assignment
	Stack s2(3);
	s1.push(4);
	s1.push(1);
	s1.push(2);
	s2.push(5);
	s2=s1;
	s2.print();
	s1=s1;
	//check that the memory allocated was filled with 0
	Stack s3(4);
	for (int i=0 ;i<=3;i++){
		std::cout<<s3.get_m_array()<<" , "<<"\n";
	}
	//check the is_Empty
	s2.pop();
	s2.pop();
	s2.pop();
	s2.pop();
	
	
	
	std::cout<<std::endl;

}
