#include "array.hpp"
#include <cstdint>
DS::Array::Array()
:size(0), 
data(nullptr)
{}

DS::Array::Array(int size)
:size(size)
,data(new int8_t[size]())
 {}

DS::Array::Array(const DS::Array& other):
size(other.size)
,data(new int8_t[size]()) {
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}

DS::Array& DS::Array::operator=(const DS::Array& other) {
    if (this != &other) {
        delete[] data;
        size = other.size;
        data = new int8_t[size];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

DS::Array::~Array() {
    delete[] data;
}

int DS::Array::getSize() const {
    return size;
}

int8_t& DS::Array::operator[](int i) {
    return data[i];
}

int8_t* DS::Array::getData() const {
    return data;
}

void DS::Array::push_back(int8_t value) {
    int8_t* new_data = new int8_t[size + 1];
    for (int i = 0; i < size; i++) {
        new_data[i] = data[i];
    }
    new_data[size] = value;
    delete[] data;
    data = new_data;
    size++;
}

