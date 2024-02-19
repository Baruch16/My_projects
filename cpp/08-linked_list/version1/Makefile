CXX= g++
CC =$(CXX)

CXXFLAGS =-Wall -pedantic -std=c++17
CXXFLAGS +=-Werror -g

main:main.o

main.o: main.cpp linked_list.inl linked_list.hpp

clean:
	$(RM) *.o main
	
