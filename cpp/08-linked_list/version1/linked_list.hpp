#ifndef SINGLE_LINKED_LIST_HPP
#define SINGLE_LINKED_LIST_HPP

#include <iostream>
namespace ds{

template <typename T>
class SingleLinkedList {

private:

  class Node {
  public:
    T data;
    Node* next;
    Node(T data)
    :data(data)
    ,next(nullptr)
    {}
    
  };
  
  Node* head;
  int size;

  

public:

  class Iterator {
  
  public:
  
   Node* current;
   Iterator(Node* node) :current(node)    {}
   
   T operator*() const {
   	return current->data;
    }
    
    Iterator& operator++() {
	current = current->next;
      	return *this;
    }
    
    bool operator!=(const Iterator& other) const {
	return current != other.current;
    }
    
  };

  SingleLinkedList()
  :head(nullptr)
  ,size(0)
  {}

  ~SingleLinkedList();
  SingleLinkedList(const SingleLinkedList<T>& other);
  SingleLinkedList<T>& operator=(const SingleLinkedList<T>& other);
  void insert_to_front(T data);
  void add_to_end(const T &value);
  void remove(T data);
  void clear();
  int getSize() const;
  bool isEmpty() const;
  void reverse();
  Iterator begin() const;
  Iterator end() const;
  Iterator getLast() const;
  void print() const;
  void weave(SingleLinkedList<T>& other);
  
  
  
};


template <typename T>
std::ostream& operator<<(std::ostream& os, const SingleLinkedList<T>& list);


#include "linked_list.inl"

}


#endif  
