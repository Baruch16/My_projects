CXX= g++
CC =$(CXX)

CXXFLAGS =-Wall -pedantic -std=c++17
CXXFLAGS +=-Werror -g

main:main.o

main.o: main.cpp template.inl template.hpp

clean:
	$(RM) *.o main
	
