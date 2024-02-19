#ifndef BRAINFUNK_HPP
#define BRAINFUNK_HPP
#include "memory.hpp"
#include "translator.hpp"
#include "code.hpp"

namespace bf{
class Brainfunk {
public:
    Memory memory;
    DS::Array opcodes;
    DS::Array instructions;
    LoopHandler loop_handler;
    Brainfunk(const char *a, int size);
    Brainfunk(const Brainfunk &other);
    Brainfunk& operator=(const Brainfunk &other);
    void run() ;
};

}
#endif
