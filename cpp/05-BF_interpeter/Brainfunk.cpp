#include "Brainfunk.hpp"
#include <iostream>

namespace bf{

Brainfunk::Brainfunk(const char *a, int size)
: memory(size)
{
    int i = 0;
    while (a[i]) i++;
    instructions = DS::Array(i);
    int j = 0;
    while (a[j]) {
        instructions[j] = a[j];
        j++;
    }
}


Brainfunk::Brainfunk(const Brainfunk &other)
: memory(other.memory), opcodes(other.opcodes), instructions(other.instructions)
{}

Brainfunk& Brainfunk::operator=(const Brainfunk &other) {
    if (this != &other) {
        memory = other.memory;
        opcodes = other.opcodes;
        instructions = other.instructions;
    }
    return *this;
}




void Brainfunk::run()  {
    for (int i = 0; i < opcodes.getSize(); i++) {
        switch (opcodes[i]) {
            case static_cast<int8_t>(Commands::MOVE_RIGHT):
                memory.moveRight();
                break;
            case static_cast<int8_t>(Commands::MOVE_LEFT):
                memory.moveLeft();
                break;
            case static_cast<int8_t>(Commands::INCREMENT):
                memory.increment();
                break;
            case static_cast<int8_t>(Commands::DECREMENT):
                memory.decrement();
                break;
            case static_cast<int8_t>(Commands::OUTPUT):
                std::cout << memory.output();
                break;
            case static_cast<int8_t>(Commands::INPUT):
                memory.input(std::cin.get());
                break;
            case static_cast<int8_t>(Commands::LOOP_START):
                loop_handler.start_loop(i, opcodes, memory);
                break;
            case static_cast<int8_t>(Commands::LOOP_END):
                loop_handler.end_loop(i, opcodes, memory);
                break;
        }
    }
}

}

