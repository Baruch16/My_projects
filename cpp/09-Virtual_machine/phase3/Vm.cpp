#include <array>
#include <functional>
#include <stack>
#include <vector>
#include <iostream>
#include "Vm.hpp"

    VMA::VMA() : codeIndex(0) 
 ,m_functions(
    { 
        add_func,
        sub_func,     
        mul_func,     
        divide_func,     
        pop_func,   
        push_func,   
        dup_func,   
        swap_func,   
        print_func,   
        printc_func,   
        inc_func,   
        dec_func,   
        call_func,
        ret_func,
        nop_func
    } 
    )
{}
    

    
void VMA::Execute(const std::vector<int32_t> &code) {
    
   codeIndex = 0;
    OpCode op = static_cast<OpCode>(code[codeIndex]);

    while (op != OpCode::HALT) {        
        m_functions[static_cast<int32_t>(op)](code);
        ++codeIndex;
        op = static_cast<OpCode>(code[codeIndex]);
}
}

int32_t VMA::GetNextData(const std::vector<int32_t> &code) {
if (static_cast<unsigned int>(codeIndex) < code.size()) {
return code[codeIndex++];
} else {
throw std::runtime_error("Not enough data to execute instruction");
}
}

void VMA::add(const std::vector<int32_t> &code)
        {
            int32_t a = m_stack.top();
            m_stack.pop();
            int32_t b = m_stack.top();
            m_stack.pop();
            m_stack.push(a + b);
        };
void VMA::sub(const std::vector<int32_t> &code)
        {
            int32_t a = m_stack.top();
            m_stack.pop();
            int32_t b = m_stack.top();
            m_stack.pop();
            m_stack.push(b - a);
        };
void VMA::mul(const std::vector<int32_t> &code)
        {
            int32_t a = m_stack.top();
            m_stack.pop();
            int32_t b = m_stack.top();
            m_stack.pop();
            m_stack.push(a * b);
        };
void VMA::divide(const std::vector<int32_t> &code)
        {
            int32_t a = m_stack.top();
            m_stack.pop();
            int32_t b = m_stack.top();
            m_stack.pop();
            m_stack.push(b / a);
        };
void VMA::pop(const std::vector<int32_t> &code)
        {
            m_stack.pop();
        };
void VMA::push(const std::vector<int32_t> &code)
        {
            int32_t data = GetNextData(code);
            m_stack.push(data);
        };
void VMA::dup(const std::vector<int32_t> &code)
        {
            int32_t top = m_stack.top();
            m_stack.push(top);
        };
void VMA::swap(const std::vector<int32_t> &code) {
           
            int32_t a = m_stack.top();
            m_stack.pop();
            int32_t b = m_stack.top();
            m_stack.pop();
            m_stack.push(a);
            m_stack.push(b);
        };
void VMA::print(const std::vector<int32_t> &code) {
        std::cout << m_stack.top() << std::endl;
        };

void VMA::printc(const std::vector<int32_t> &code) {
        char c = static_cast<char>(m_stack.top());
        if(c>=0 && c<=127){
        std::cout << c << std::endl;
        }
        else{
            std::cout<<"No Askii for this value";
        }
        };
void VMA::halt(const std::vector<int32_t> &code) {
        return;
        };
void VMA::inc(const std::vector<int32_t> &code) {
        int32_t top = m_stack.top();
        m_stack.pop();
        m_stack.push(top + 1);
        };
void VMA::dec(const std::vector<int32_t> &code) {
        int32_t top = m_stack.top();
        m_stack.pop();
        m_stack.push(top - 1);
        };
void VMA::nop(const std::vector<int32_t> &code) {
        
        };
void VMA::call(const std::vector<int32_t> &code) {
            if(!m_callStack.empty()){
            m_callStack.push(codeIndex + 1);
            codeIndex = GetNextData(code);
            }
            else{
                std::cerr<<"Error: Stack is empty:"<<std::endl;
            }
        };
void VMA::ret(const std::vector<int32_t> &code) {
            if(!m_callStack.empty()){
            codeIndex = m_callStack.top();
            m_callStack.pop();
            
            }
            else{
                std::cerr<<"Error: Stack is empty:"<<std::endl;
            }
        };