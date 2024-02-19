#ifndef MEMORY_HPP
#define MEMORY_HPP
#include "array.hpp"
namespace bf{
class Memory {

private:

        DS::Array array;
        int8_t*ptr;
public:
	
	Memory();
        explicit Memory(int size);
        Memory(const Memory&other);
        Memory& operator=(const Memory &other);
        ~Memory();
        void moveRight();
        void moveLeft();
        void increment();
        void decrement();
        int8_t output();
        void input(char c);
        int8_t* get_ptr();
};
}
#endif
