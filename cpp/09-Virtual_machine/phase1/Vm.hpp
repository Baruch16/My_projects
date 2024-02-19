#include <stack>
#include <vector>
#include <cstdint>

enum class OpCode{
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
    NOP,
    HALT,
    INC,
    DEC,

    };

class VMA{

public:
VMA()=default;
void Execute(const std::vector<int32_t>& code);  

private:
void ExecuteOpCode(OpCode opCode,const std::vector<int32_t>& code);
int32_t GetNextData(const std::vector<int32_t>& code);
std::stack<int32_t> m_stack;
int codeIndex =0;


};