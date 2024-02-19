#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <iostream>
#include "container.hpp"


using namespace co;



void test_with_classes(){
class Student {
public:
  Student(const std::string &name, int grade) : name(name), grade(grade) {}
  std::string name;
  int grade;


bool smaller(const Student &lhs, const Student &rhs) {
  return lhs.grade < rhs.grade;
}

static bool bigger(const Student &lhs, const Student &rhs) {
    return lhs.grade > rhs.grade;
}


};



  std::vector<Student> students = {
    {"Alice", 90},
    {"Bob", 85},
    {"Charlie", 95}
  };

  if (is_sorted_obj(students,Student::bigger)) {
    std::cout << "The vector of students is sorted." << std::endl;
  } else {
    std::cout << "The vector of students is not sorted." << std::endl;
  }

}


void test_temp_is_sorted(){
	
	//int
	std::array<int, 19> arr_int = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 20};

	if(is_sorted(arr_int)){
		std::cout << "The array of type int is sorted"<<"\n";
	}
	else std::cout << "The array of type int is not sorted"<<"\n";
	
	
	//char
	std::array<char,8> arr_char = {'a','b','b','d','e','f','g','h'};

	if(is_sorted(arr_char)){
		std::cout << "The array of type int is sorted"<<"\n";
	}
	else std::cout << "The array of type int is not sorted"<<"\n";
	
	//string
	
	
	std::array<std::string, 7> arr_string = {"hello", "world", "hello", "this", "is", "a", "test"};

	if(is_sorted(arr_string)){
		std::cout << "The array of type int is sorted"<<"\n";
	}
	else std::cout << "The array of type int is not sorted"<<"\n";

}

void test_temp_duplicate(){

	std::array<int, 5> arr = {1, 2, 3, 4, 2};

	std::array<int, 5>::iterator duplicate = findFirstDuplicate(arr);

	if (duplicate != arr.end()) {
		std::cout << "First duplicate in array: " << *duplicate << std::endl;
	} else {
		std::cout << "No duplicates in array found" << std::endl;
	}

	// std::vector
	std::vector<int> vec = {1, 2, 3, 4, 2};

	std::vector<int>::iterator duplicate_vec = findFirstDuplicate(vec);

	if (duplicate_vec != vec.end()) {
		std::cout << "First duplicate in vector: " << *duplicate_vec << std::endl;
	} else {
		std::cout << "No duplicates in vector found" << std::endl;
	}

	// std::list
	std::list<int> lst = {1, 2, 3, 4, 2};

	std::list<int>::iterator duplicate_lst = findFirstDuplicate(lst);

	if (duplicate_lst != lst.end()) {
		std::cout << "First duplicate in list: " << *duplicate_lst << std::endl;
	} else {
		std::cout << "No duplicates in list found" << std::endl;
	}

	 
}


void test_temp_unique(){
	
  std::array<char, 5> arr = {'a', 'b', 'c', 'd', 'e'};

  std::array<char, 5>::iterator unique =  findFirstUnique(arr);

  if (unique != arr.end()) {
    std::cout << "First unique in array: " << *unique << std::endl;
  } else {
    std::cout << "No unique in array found" << std::endl;
  }

  // std::vector
  std::vector<int> vec = {1, 2, 3, 4, 2};

  std::vector<int>::iterator unique_vec =  findFirstUnique(vec);

  if (unique_vec != vec.end()) {
    std::cout <<"First unique in array:: " << *unique_vec << std::endl;
  } else {
    std::cout << "No unique in array found" << std::endl;
  }

  // std::list
  std::list<double> lst = {1.2, 2.3, 3.4, 4.5, 2.3};

  std::list<double>::iterator unique_lst =  findFirstUnique(lst);

  if (unique_lst != lst.end()) {
    std::cout << "First unique in array:: " << *unique_lst << std::endl;
  } else {
    std::cout << "No unique in array found" << std::endl;
  }
  
}

int main() {

    test_temp_is_sorted();
    std::cout<<"\n";
    test_temp_duplicate();
    test_temp_unique();
   test_with_classes();
    
}
