CXX = g++
CC = g++

CXXFLAGS = -Wall -pedantic -std=c++17
CXXFLAGS+=-Werror -g

main: main.o Brainfunk.o array.o memory.o code.o translator.o
	$(CXX) $(CXXFLAGS) main.o Brainfunk.o array.o memory.o code.o translator.o -o main

main.o: main.cpp Brainfunk.hpp 
	$(CXX) $(CXXFLAGS) -c main.cpp

Brainfunk.o: Brainfunk.hpp Brainfunk.cpp 
	$(CXX) $(CXXFLAGS) -c Brainfunk.cpp

array.o: array.hpp array.cpp
	$(CXX) $(CXXFLAGS) -c array.cpp

memory.o: memory.hpp memory.cpp 
	$(CXX) $(CXXFLAGS) -c memory.cpp

code.o : code.cpp code.hpp
	$(CXX) $(CXXFLAGS) -c code.cpp
	
//translator.o : translator.hpp translator.cpp
	$(CXX) $(CXXFLAGS) -c translator.cpp
run: main
	./main

clean: 
	$(RM) *.o ./main
