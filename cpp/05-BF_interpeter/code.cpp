#include "code.hpp"

namespace bf{

LoopHandler::LoopHandler()
{}
    
void LoopHandler::start_loop(int &i,DS:: Array &opcodes, Memory &memory) {
        if (memory.output() == 0) {
            int loop_count = 1;
            while (loop_count > 0) {
                i++;
                if (opcodes[i] ==static_cast<int8_t>(Commands::LOOP_START)) {
                    loop_count++;
                } else if (opcodes[i] == static_cast<int8_t>(Commands::LOOP_END)) {
                    loop_count--;
                	}
            }
        }
}


               
void LoopHandler::end_loop(int &i, DS::Array &opcodes, Memory &memory){
        if (memory.output() != 0) {
            int loop_count = 1;
            while (loop_count > 0) {
                i--;
                if (opcodes[i] == static_cast<int8_t>(Commands::LOOP_START)) {
                    loop_count--;
                } else if (opcodes[i] ==static_cast<int8_t>( Commands::LOOP_END)) {
                    loop_count++;
                	}
            }
        }
}

}
