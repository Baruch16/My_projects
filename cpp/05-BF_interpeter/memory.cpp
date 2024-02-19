#include "memory.hpp"
#include <cstdio>

namespace bf{

Memory::Memory()
: array(1)
, ptr(array.getData())
{}

Memory::Memory(int size)
: array(size)
, ptr(array.getData())
{}

Memory::Memory(const Memory&other)
: array(other.array)
, ptr(array.getData() + (other.ptr - other.array.getData()))
{}

Memory& Memory::operator=(const Memory &other) 
{
    if (this != &other) {
        array = other.array;
        ptr = array.getData() + (other.ptr - other.array.getData());
    }
    return *this;
}

Memory::~Memory() {}

void Memory::moveRight() {
    ptr++;
    if (ptr - array.getData() >= array.getSize()) {
        ptr = array.getData() + array.getSize() - 1;
    }
}

int8_t* Memory::get_ptr(){
	return ptr;
}

void Memory::moveLeft() {
    ptr--;
    if (ptr < array.getData()) {
        ptr = array.getData();
    }
}


void Memory::increment() {
    (*ptr)++;
}

void Memory::decrement() {
    (*ptr)--;
}

int8_t Memory::output() {
    return *ptr;
}

void Memory::input(char c) {
    *ptr=c;
}
}
