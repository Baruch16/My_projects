#include <iostream>
#include "Vm.hpp"
#include <cstdint>

void VMA::Execute(const std::vector<int32_t> &code)
{
    while (true)
    {
        OpCode opCode = static_cast<OpCode>(code[codeIndex++]);
        if (opCode == OpCode::HALT)
        {
            break;
        }
        ExecuteOpCode(opCode, code);
    }
}

void VMA::ExecuteOpCode(OpCode opCode, const std::vector<int32_t> &code)
{
    switch (opCode)
    {
    case OpCode::ADD:
    {
        int32_t a = m_stack.top();
        m_stack.pop();
        int32_t b = m_stack.top();
        m_stack.pop();
        m_stack.push(a + b);
        break;
    }
    case OpCode::SUB:
    {
        int32_t a = m_stack.top();
        m_stack.pop();
        int32_t b = m_stack.top();
        m_stack.pop();
        m_stack.push(b - a);
        break;
    }
    case OpCode::MUL:
    {
        int32_t a = m_stack.top();
        m_stack.pop();
        int32_t b = m_stack.top();
        m_stack.pop();
        m_stack.push(a * b);
        break;
    }
    case OpCode::DIV:
    {
        int32_t a = m_stack.top();
        m_stack.pop();
        int32_t b = m_stack.top();
        m_stack.pop();
        m_stack.push(b / a);
        break;
    }
    case OpCode::POP:
    {
        m_stack.pop();
        break;
    }
    case OpCode::PUSH:
    {
        int32_t data = GetNextData(code);
        m_stack.push(data);
        break;
    }
    case OpCode::DUP:
    {
        int32_t top = m_stack.top();
        m_stack.push(top);
        break;
    }
    case OpCode::SWAP:
    {
        int32_t a = m_stack.top();
        m_stack.pop();
        int32_t b = m_stack.top();
        m_stack.pop();
        m_stack.push(a);
        m_stack.push(b);
        break;
    }
    case OpCode::PRINT:
    {
        std::cout << m_stack.top() << std::endl;
        m_stack.pop();
        break;
    }
    case OpCode::PRINTC:
    {
        int32_t top = m_stack.top();
        if (top >= 0 && top <= 127)
        {
            std::cout << static_cast<char>(top);
            std::cout << top << std::endl;
            m_stack.pop();
        }
        else
        {
            std::cout << "Not an existing ASCII character.";
        }
        break;
        
    }
    case OpCode::HALT:
    {
        break;
    }
    case OpCode::INC:
    {
        int32_t top = m_stack.top();
        m_stack.pop();
        m_stack.push(top + 1);
        break;
    }
    case OpCode::DEC:
    {
        int32_t top = m_stack.top();
        m_stack.pop();
        m_stack.push(top - 1);
        break;
    }
    case OpCode::NOP:
    {
        break;
    }
    }
}
int32_t VMA::GetNextData(const std::vector<int32_t> &code)
{
    int32_t data = code[codeIndex++];
    return data;
}