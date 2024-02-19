CC = gcc

main: q5main.o q5mC.o
	gcc -o main q5main.o q5mC.o

q5main.o : q5main.c  q5.h q5mC.c

q5main-1.o : q5main.c q5.h

run : main
	./main
	
clean :
	$(RM) *.o ./main