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
    NOP,
    CALL,
    RET
};

class VMA {
public:
    VMA();
    void Execute(const std::vector<int32_t> &code);
    void execute(std::vector<int32_t> const& opcodes, OpCode command);

    void add(std::vector<int32_t> const& code);
    void sub(std::vector<int32_t> const& code); 
    void mul(std::vector<int32_t> const& code); 
    void divide(std::vector<int32_t> const& code); 
    void pop(std::vector<int32_t> const& code); 
    void push(std::vector<int32_t> const& code); 
    void dup(std::vector<int32_t> const& code); 
    void swap(std::vector<int32_t> const& code); 
    void print(std::vector<int32_t> const& code); 
    void printc(std::vector<int32_t> const& code); 
    void inc(std::vector<int32_t> const& code); 
    void dec(std::vector<int32_t> const& code); 
    void halt(std::vector<int32_t> const& code); 
    void call(std::vector<int32_t> const& code); 
    void ret(std::vector<int32_t> const& code);
    void nop(std::vector<int32_t> const& code);


    std::function<void(std::vector<int32_t> const&)> add_func = std::bind(&VMA::add, this, std::placeholders::_1);
    std::function<void(std::vector<int32_t> const&)> sub_func = std::bind(&VMA::sub, this, std::placeholders::_1);
    std::function<void(std::vector<int32_t> const&)> mul_func = std::bind(&VMA::mul, this, std::placeholders::_1);
    std::function<void(std::vector<int32_t> const&)> divide_func = std::bind(&VMA::divide, this, std::placeholders::_1);
    std::function<void(std::vector<int32_t> const&)> pop_func = std::bind(&VMA::pop, this, std::placeholders::_1);
    std::function<void(std::vector<int32_t> const&)> push_func = std::bind(&VMA::push, this, std::placeholders::_1);
    std::function<void(std::vector<int32_t> const&)> dup_func = std::bind(&VMA::dup, this, std::placeholders::_1);
    std::function<void(std::vector<int32_t> const&)> swap_func = std::bind(&VMA::swap, this, std::placeholders::_1);
    std::function<void(std::vector<int32_t> const&)> print_func = std::bind(&VMA::print, this, std::placeholders::_1);
    std::function<void(std::vector<int32_t> const&)> printc_func = std::bind(&VMA::printc, this, std::placeholders::_1);
    std::function<void(std::vector<int32_t> const&)> inc_func = std::bind(&VMA::inc, this, std::placeholders::_1);
    std::function<void(std::vector<int32_t> const&)> dec_func = std::bind(&VMA::dec, this, std::placeholders::_1);
    std::function<void(std::vector<int32_t> const&)> call_func = std::bind(&VMA::call, this, std::placeholders::_1);
    std::function<void(std::vector<int32_t> const&)> ret_func = std::bind(&VMA::ret, this, std::placeholders::_1);
    std::function<void(std::vector<int32_t> const&)> nop_func = std::bind(&VMA::nop, this, std::placeholders::_1);

private:
    std::stack<int32_t> m_callStack;
    int32_t GetNextData(const std::vector<int32_t> &code);
    std::stack<int32_t> m_stack;
    int codeIndex;
    std::array<std::function<void(std::vector<int32_t> const&)>, 18> m_functions;
    //std::array<std::function<void(const std::vector<int32_t> &)>, static_cast<int>(OpCode::NOP) + 1> m_ops;
};

#endif
