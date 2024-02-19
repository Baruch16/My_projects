CXX= g++
CC =$(CXX)

CXXFLAGS =-Wall -pedantic -std=c++17
CXXFLAGS +=-Werror -g

main:main.o Vm.o

main.o: main.cpp Vm.cpp

Vm.o:Vm.cpp 

clean:
	$(RM) *.o main
	
