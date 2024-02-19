#include"Vm.hpp"

void test_(){

    VMA vm;
std::vector<int32_t> code = {
static_cast<int32_t>(OpCode::PUSH), 10,
static_cast<int32_t>(OpCode::PUSH), 20,
static_cast<int32_t>(OpCode::ADD),
static_cast<int32_t>(OpCode::PRINT),
static_cast<int32_t>(OpCode::PUSH), 12,
static_cast<int32_t>(OpCode::PUSH), 8,
static_cast<int32_t>(OpCode::DUP),
static_cast<int32_t>(OpCode::INC),
static_cast<int32_t>(OpCode::INC),
static_cast<int32_t>(OpCode::MUL),
static_cast<int32_t>(OpCode::SUB),
static_cast<int32_t>(OpCode::DUP),
static_cast<int32_t>(OpCode::PRINT),
static_cast<int32_t>(OpCode::PRINTC),
static_cast<int32_t>(OpCode::PUSH),63,
static_cast<int32_t>(OpCode::CALL),9,
static_cast<int32_t>(OpCode::NOP),
static_cast<int32_t>(OpCode::CALL),10,
static_cast<int32_t>(OpCode::NOP),
static_cast<int32_t>(OpCode::HALT),
static_cast<int32_t>(OpCode::NOP),
static_cast<int32_t>(OpCode::INC),
static_cast<int32_t>(OpCode::DUP),
static_cast<int32_t>(OpCode::PRINTC),
static_cast<int32_t>(OpCode::RET),
static_cast<int32_t>(OpCode::HALT)
};
vm.Execute(code);

}

int main() {

test_();
}