

CXX = g++
CC = g++

CFLAGS = -Wall -pedantic -Werror

main: main.o rational.o

main.o: main.cpp rational.cpp rational.hpp

rational.o: rational.cpp rational.hpp

run: main
	./main
	
clean: 
	$(RM) *.o ./main
