#include <array>
#include <functional>
#include <stack>
#include <vector>
#include <iostream>
#include "Vm.hpp"


    VMA::VMA() : m_stack(), codeIndex(0)
    {
        m_ops[static_cast<int>(OpCode::ADD)] = [this](const std::vector<int32_t> &code)
        {
            int32_t a = m_stack.top();
            m_stack.pop();
            int32_t b = m_stack.top();
            m_stack.pop();
            m_stack.push(a + b);
        };
        m_ops[static_cast<int>(OpCode::SUB)] = [this](const std::vector<int32_t> &code)
        {
            int32_t a = m_stack.top();
            m_stack.pop();
            int32_t b = m_stack.top();
            m_stack.pop();
            m_stack.push(b - a);
        };
        m_ops[static_cast<int>(OpCode::MUL)] = [this](const std::vector<int32_t> &code)
        {
            int32_t a = m_stack.top();
            m_stack.pop();
            int32_t b = m_stack.top();
            m_stack.pop();
            m_stack.push(a * b);
        };
        m_ops[static_cast<int>(OpCode::DIV)] = [this](const std::vector<int32_t> &code)
        {
            int32_t a = m_stack.top();
            m_stack.pop();
            int32_t b = m_stack.top();
            m_stack.pop();
            m_stack.push(b / a);
        };
        m_ops[static_cast<int>(OpCode::POP)] = [this](const std::vector<int32_t> &code)
        {
            m_stack.pop();
        };
        m_ops[static_cast<int>(OpCode::PUSH)] = [this](const std::vector<int32_t> &code)
        {
            int32_t data = GetNextData(code);
            m_stack.push(data);
        };
        m_ops[static_cast<int>(OpCode::DUP)] = [this](const std::vector<int32_t> &code)
        {
            int32_t top = m_stack.top();
            m_stack.push(top);
        };
        m_ops[static_cast<int>(OpCode::SWAP)] = [this](const std::vector<int32_t> &code) {
           
            int32_t a = m_stack.top();
            m_stack.pop();
            int32_t b = m_stack.top();
        m_stack.pop();
        m_stack.push(a);
        m_stack.push(b);
        };
        m_ops[static_cast<int>(OpCode::PRINT)] = [this](const std::vector<int32_t> &code) {
        std::cout << m_stack.top() << std::endl;
        };

        m_ops[static_cast<int>(OpCode::PRINTC)] = [this](const std::vector<int32_t> &code) {
        char c = static_cast<char>(m_stack.top());
        if(c>=0 && c<=127){
        std::cout << c << std::endl;
        }
        else{
            std::cout<<"No Askii for this value";
        }
        };
        m_ops[static_cast<int>(OpCode::HALT)] = [this](const std::vector<int32_t> &code) {
        return;
        };
        m_ops[static_cast<int>(OpCode::INC)] = [this](const std::vector<int32_t> &code) {
        int32_t top = m_stack.top();
        m_stack.pop();
        m_stack.push(top + 1);
        };
        m_ops[static_cast<int>(OpCode::DEC)] = [this](const std::vector<int32_t> &code) {
        int32_t top = m_stack.top();
        m_stack.pop();
        m_stack.push(top - 1);
        };
        m_ops[static_cast<int>(OpCode::NOP)] = [this](const std::vector<int32_t> &code) {
        // Do nothing
        };
    }

    
void VMA::Execute(const std::vector<int32_t> &code) {
    while (static_cast<unsigned int>(codeIndex) < code.size()) {
        OpCode op = static_cast<OpCode>(code[codeIndex++]);
        m_ops[static_cast<int>(op)](code);
}
}

int32_t VMA::GetNextData(const std::vector<int32_t> &code) {
if (static_cast<unsigned int>(codeIndex) < code.size()) {
return code[codeIndex++];
} else {
throw std::runtime_error("Not enough data to execute instruction");
}
}


        
