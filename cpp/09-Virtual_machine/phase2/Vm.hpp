#ifndef VMA_HPP
#define VMA_HPP

#include <array>
#include <functional>
#include <stack>
#include <vector>
#include <iostream>

enum class OpCode {
    ADD,
    SUB,
    MUL,
    DIV,
    POP,
    PUSH,
    DUP,
    SWAP,
    PRINT,
    PRINTC,
    HALT,
    INC,
    DEC,
    NOP
};

class VMA {
public:
    VMA();
    void Execute(const std::vector<int32_t> &code);

private:
    int32_t GetNextData(const std::vector<int32_t> &code);
    std::stack<int32_t> m_stack;
    int codeIndex;
    std::array<std::function<void(const std::vector<int32_t> &)>, static_cast<int>(OpCode::NOP) + 1> m_ops;
};

#endif
