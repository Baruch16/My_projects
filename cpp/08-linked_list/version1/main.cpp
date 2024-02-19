#include <iostream>
#include "linked_list.hpp"

using namespace ds;
void test1(){
	
	SingleLinkedList<char> list;
	list.insert_to_front('a');
	list.insert_to_front('b');
	list.insert_to_front('c');
	
	std::cout << "List:" ;
	list.print();
	std::cout<<std::endl;

}


void test2(){

	SingleLinkedList<int> list;
	list.insert_to_front(1);
	list.insert_to_front(2);
	list.insert_to_front(3);
	
	
	list.remove(2);
	std::cout << "After removing:" ;
	list.print();
	std::cout<<std::endl;
		
}
	
void test3(){
	
	SingleLinkedList<int> list;
	list.insert_to_front(1);
	list.insert_to_front(2);
	list.insert_to_front(3);
	
	list.reverse();
	std::cout << "After reversing: ";
	list.print();
	std::cout<<std::endl;

}


void test4(){

	SingleLinkedList<int> list;
	list.insert_to_front(1);
	list.insert_to_front(2);
	list.insert_to_front(3);
	
	std::cout << "Size: " << list.getSize() << std::endl;

}

void test5(){

	
	SingleLinkedList<int> ll;
  	ll.insert_to_front(2);
  	ll.insert_to_front(3);
  	ll.insert_to_front(4);
  	std::cout<<"using iterator functions:";
  	SingleLinkedList<int>::Iterator it = ll.begin();
  	std::cout<<"begin"<<*ll.begin();
  	while (it != ll.end())
  	{
    		std::cout << *it << " ";
    		++it;
  	}
  
  	std::cout << std::endl;
  	
 }
 
void test6(){

	SingleLinkedList<int> ll;
  	ll.insert_to_front(2);
  	ll.insert_to_front(3);
  	std::cout<<"Getting last element:";
	SingleLinkedList<int>::Iterator it = ll.getLast();
	std::cout<<*it;
	std::cout << std::endl;
}

void test7(){

	SingleLinkedList<int> ll;
  	ll.insert_to_front(1);
  	ll.insert_to_front(2);
  	ll.insert_to_front(3);
  	ll.insert_to_front(4);
  	
  	SingleLinkedList<int> list;
	list.insert_to_front(9);
	list.insert_to_front(8);
	list.insert_to_front(7);
	list.insert_to_front(6);
	std::cout<<"Getting the weaved list:";
	list.weave(ll);
	list.print();
	
}

void test8(){

	SingleLinkedList<char> list;
	list.insert_to_front('a');
	list.insert_to_front('b');
	list.insert_to_front('c');
	SingleLinkedList<int> ll;
  	ll.insert_to_front(1);
  	ll.insert_to_front(2);
  	ll.insert_to_front(3);
  	ll.insert_to_front(4);
  	std::cout<<std::endl;
  	std::cout<<"streaming different types"<<std::endl;
	std::cout << "List:" <<list<<"list2:"<<" "<<ll;
	std::cout<<std::endl;
}

void test9(){

	SingleLinkedList<char> list;
	list.insert_to_front('a');
	list.insert_to_front('b');
	list.insert_to_front('c');
	list.add_to_end('v');
	std::cout << "List:" <<list;

}
int main() {
	
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
	test9();
	
}
