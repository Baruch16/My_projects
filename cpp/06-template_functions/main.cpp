#include "template.hpp" 
#include <iostream>

using namespace tp;

void test1()
{
	char arr[]={'a','b','b','d','e','f','g','h'};
	
	size_t first_uniq = firstUnique(arr,8);
	char min_val = smallest(arr,8);
	
	std::cout<< "test 1: <char>\n";
	std::cout<< "First Unique index is:"<<" "<< first_uniq <<"\n";
	std::cout<< "Smallest element is:"<<" "<<min_val<<"\n";
}

void test2()
{
	int arr[]={2,2,3,3,1,8,1,9,8};
	
	size_t first_uniq = firstUnique(arr,9);
	int min_val = smallest(arr,9);
	
	std::cout<< "test 2: <int>\n";
	std::cout<< "First Unique index is:"<<" "<< first_uniq <<"\n";
	std::cout<< "Smallest element is:"<<" "<<min_val<<"\n";
}

void test3()
{
	double arr[]={2.2, 3.2, 2.2, 1.1};
	
	size_t first_uniq = firstUnique(arr,4);
	double min_val = smallest(arr,4);
	
	std::cout<< "test 3: <double>\n";
	std::cout<< "First Unique index is:"<<" "<< first_uniq <<"\n";
	std::cout<< "Smallest element is:"<<" "<<min_val<<"\n";
}

void test4()
{
   std::string arr[] = {"hello", "world", "hello", "this", "is", "a", "test"};
   size_t first_uniq = firstUnique(arr,8);
   
	
   std::cout<< "test 4: <std::string>\n";
   std::cout<< "First Unique index is:"<<" "<< first_uniq <<"\n";
   

}

int main(){

	test1();
	std::cout << "\n";
	test2();
	std::cout << "\n";
	test3();
	std::cout << "\n";
	test4();
	return 0;	
}
	
