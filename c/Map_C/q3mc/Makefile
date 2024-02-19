CC = gcc

CFLAGS = -c
 

main : mainq3.o q3.o
	gcc -o main mainq3.o q3.o
	
mainq3.o : mainq3.c q3.c q3.h

q3.o : q3.c q3.h

run : main
	./main

clean :
	$(RM)  *.o main
