#ifndef SINGLE_LINKED_LIST_HPP
#define SINGLE_LINKED_LIST_HPP

#include <cstddef>

namespace ds{

template <typename T>
class LinkedList {
private:


	class Node {
	public:
	T data;
	Node *next;
    	Node(const T &d) : data(d), next(nullptr) {}
};

	template <typename U>
    	class Iterator {
        

    	public:
    	Node *current;
        Iterator(Node *node) : current(node) {}
        U &operator*() const { return current->data; }
        Iterator &operator++() { current = current->next; return *this; }
        bool operator!=(const Iterator &other) const { return current != other.current; }
    };

	Node *head;
	Node *tail;
	std::size_t sz;

	void copyList(const LinkedList &other);
	void deleteList();
public:
	LinkedList() : head(nullptr), tail(nullptr), sz(0) {}
	LinkedList(const LinkedList &other);
	LinkedList &operator=(const LinkedList &other);
	~LinkedList();


	void push_back(const T &data);
	void pop_back();
	void push_front(const T &data);
	void pop_front();
	std::size_t size() const;
	void print(std::ostream& os) const;
	LinkedList<T> weave(const LinkedList<T> &other) const;
	
	Iterator<T> begin();
    	Iterator<T> end();
};

template <typename T>
std::ostream& operator<<(std::ostream &os, const LinkedList<T> &list);

#include "linked_list.inl"

}


#endif  
