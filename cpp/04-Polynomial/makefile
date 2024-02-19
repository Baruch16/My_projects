
CXX = g++
CC = g++

CXXFLAGS = -Wall -pedantic -std=c++17
CXXFLAGS+=-Werror

main: main.o polynomial.o ../01-Rational/rational.o rational_array.o

main.o: main.cpp polynomial.hpp polynomial.cpp ../01-Rational/rational.hpp

polynomial.o: polynomial.hpp polynomial.cpp ../01-Rational/rational.hpp

../01-Rational/rational.o: ../01-Rational/rational.cpp ../01-Rational/rational.hpp

rational_array.o:rational_array.cpp rational_array.hpp

run: main
	./main
	
clean: 
	$(RM) *.o ./main
