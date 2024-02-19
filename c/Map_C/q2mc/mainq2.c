#include "q2.h"

void main(int argc,char* argv []){
	int pointer;
	for (pointer=1; pointer<argc ; pointer++){
		if (**(argv+pointer) <= '9' && **(argv+pointer) >= '0')
            insert(*(argv+pointer));
        else
            break;
    }
    	for(pointer; pointer < argc; ++pointer)
        	calculate(**(argv+pointer));
        print_result();
}

