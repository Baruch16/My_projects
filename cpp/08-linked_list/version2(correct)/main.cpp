#include <iostream>
#include "linked_list.hpp"

using namespace ds;



int main() {
	
	LinkedList<int> list1;
	LinkedList<int> list2;
	
	list1.push_back(1);
	list1.push_back(2);
	list1.push_back(3);

	list2.push_back(4);
	list2.push_back(5);
	list2.push_back(6);

	std::cout << "List 1: " << list1 << std::endl;
	std::cout << "List 2: " << list2 << std::endl;

	list1.push_front(0);
	list2.pop_back();

	std::cout << "List 1 after push_front(0): " << list1 << std::endl;
	std::cout << "List 2 after pop_back(): " << list2 << std::endl;

	list1.pop_front();

	std::cout << "List 1 after pop_front(): " << list1 << std::endl;

	std::cout << "List 1 size: " << list1.size() << std::endl;
	std::cout << "List 2 size: " << list2.size() << std::endl;

	LinkedList<int> list3 = list1.weave(list2);
	std::cout << "Weaved List: " << list3 << std::endl;

return 0;
	
	
}
