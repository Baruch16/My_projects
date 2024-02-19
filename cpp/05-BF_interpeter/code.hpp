#ifndef CODE_HPP
#define CODE_HPP
#include "array.hpp"
#include "memory.hpp"
#include "enum.hpp"
namespace bf{
class LoopHandler{
public:
	LoopHandler();
	void start_loop(int &i, DS::Array &opcodes, Memory &memory) ;
	void end_loop(int &i,DS:: Array &opcodes, Memory &memory) ;
};
}
#endif
