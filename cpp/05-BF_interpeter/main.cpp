#include "Brainfunk.hpp"
#include <iostream>

using namespace bf;

int main() {
    const char code[] = "++++++++[>+>++++<<-]>++>>+<[-[>>+<<-]+>>]>+[-<<<[->[+[-]+>++>>>-<<]<[<]>>++++++[<<+++++>>-]+<<++.[-]<<]>.>+[>>]>+]";
    Brainfunk brf(code, 300);
    fillOpcodes(brf.opcodes,brf.instructions);
    brf.run();
    return 0;
}

