#ifndef NAMESPACE_HPP
#define NAMESPACE_HPP
#include "translator.hpp"
#include "enum.hpp"
#include "array.hpp"

namespace bf{
void fillOpcodes(DS::Array& opcodes, DS::Array& instructions) {
    for (int i = 0; i < instructions.getSize(); i++) {
        switch (instructions[i]) {
            case '>':
                opcodes.push_back(static_cast<int8_t>(Commands::MOVE_RIGHT));
                break;
            case '<':
                opcodes.push_back(static_cast<int8_t>(Commands::MOVE_LEFT));
                break;
            case '+':
                opcodes.push_back(static_cast<int8_t>(Commands::INCREMENT));
                break;
            case '-':
                opcodes.push_back(static_cast<int8_t>(Commands::DECREMENT));
                break;
            case '.':
                opcodes.push_back(static_cast<int8_t>(Commands::OUTPUT));
                break;
            case ',':
                opcodes.push_back(static_cast<int8_t>(Commands::INPUT));
                break;
            case '[':
                opcodes.push_back(static_cast<int8_t>(Commands::LOOP_START));
                break;
            case ']':
                opcodes.push_back(static_cast<int8_t>(Commands::LOOP_END));
                break;
        }
    }
}

}
#endif

