

CXX = g++
CC = g++

CXXFLAGS = -Wall -pedantic -std=c++17
CXXFLAGS+=-Werror

main: main.o arrstack.o

main.o: main.cpp arrstack.cpp arrstack.hpp

arrstack.o: arrstack.cpp arrstack.hpp

run: main
	./main
	
clean: 
	$(RM) *.o ./main
