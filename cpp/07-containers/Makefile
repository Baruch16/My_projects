CXX= g++
CC =$(CXX)

CXXFLAGS =-Wall -pedantic -std=c++17
CXXFLAGS +=-Werror -g

main:main.o

main.o: main.cpp container.inl container.hpp

clean:
	$(RM) *.o main
	
