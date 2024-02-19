#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <cstdint>

namespace DS{
class Array {
public:
    Array();
    explicit Array(int size);
    Array(const Array& other);
    Array& operator=(const Array& other);
    ~Array();

    int getSize() const;
    int8_t &operator[](int i);
    int8_t* getData() const;
    void push_back(int8_t data) ;

private:
    int size;
    int8_t* data;
};
}
#endif
