CXX= g++
CC =$(CXX)

CXXFLAGS =-Wall -pedantic -std=c++17
CXXFLAGS +=-Werror -g

main:main.o transformation_classes.o 

main.o: main.cpp output.hpp

transformation_classes.o:transformation_classes.cpp


clean:
	$(RM) *.o main
	