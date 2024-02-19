#include <iostream>
#include "arrstack.hpp"
#include <algorithm>
#include <cassert>

Stack::Stack()
{
	this->m_size=default_size;
	m_array=new int[default_size];
	
	
	
	assert (m_array);
	m_top=-1;
}

Stack::Stack(int size)
{
	this->m_size=size;
	m_array=new int[m_size];

	
	assert (m_array);
	m_top=-1;
}

Stack::Stack(const Stack &other)
{
	m_size=other.m_size;
	m_array=new int[m_size];
	
	
	assert (m_array);
	m_top=other.m_top;
	std::copy(other.m_array,other.m_array+m_size,m_array);
}

Stack& Stack:: operator=(const Stack& other)
{
	if (this==&other){
		return *this;
	}
	m_size=other.m_size;
	delete[] m_array;
	m_top=other.m_top;
	m_array=new int[m_size];
	
	
	
	std::copy(other.m_array,other.m_array+m_size,m_array);
	return *this;
}
	
Stack::~Stack()
{	
	delete[] m_array;
}

bool Stack::isEmpty() const
{
	if(m_top==-1){
		return true;
	}
	return false;	
}

bool Stack::isFull() const
{
	if(m_top==m_size-1){
		return true;
	}
	return false;
}

void Stack::push(int x)
{
	if(isFull()){
		std::cout<<"Error the stack is full"<<std::endl;
		return;
	}
	m_array[++m_top]=x;
}

int Stack::pop()
{
	if(isEmpty()){
		std::cout<<"Error the stack is empty"<<std::endl;
		exit(0);
	}
	return m_array[m_top--];
}
	
int Stack::topEl() const
 {	
 	if(isEmpty()){
		std::cout<<"Error the stack is empty"<<std::endl;
		exit(0);
	}
 	return m_array[m_top];
 }

int Stack::get_m_top() const
{
	return m_top;
}

int Stack::get_m_array()const
{
	return *m_array;
}

void Stack::print() const
{	if(isEmpty()){
		std::cout<<"Error the stack is empty"<<std::endl;
		return ;
	}
	for (int i=0 ;i<=get_m_top();i++){
		std::cout<<m_array[i]<<" , ";
	}
	std::cout<<std::endl;
}
	
