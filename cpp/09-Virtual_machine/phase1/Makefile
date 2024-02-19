CXX= g++
CC =$(CXX)

CXXFLAGS =-Wall -pedantic -std=c++17
CXXFLAGS +=-Werror -g

main:main.o Vm.o

main.o: main.cpp Vm.cpp Vm.hpp

Vm.o:Vm.cpp Vm.hpp

clean:
	$(RM) *.o main
	
