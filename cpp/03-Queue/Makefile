

CXX = g++
CC = g++

CXXFLAGS = -Wall -pedantic -std=c++17
CXXFLAGS+=-Werror

main: main.o queue.o ../02-Stack/arrstack.o

main.o: main.cpp queue.hpp queue.cpp ../02-Stack/arrstack.hpp 

queue.o: queue.hpp queue.cpp ../02-Stack/arrstack.cpp ../02-Stack/arrstack.hpp

../02-Stack/arrstack.o: ../02-Stack/arrstack.cpp ../02-Stack/arrstack.hpp

run: main
	./main
	
clean: 
	$(RM) *.o ./main
