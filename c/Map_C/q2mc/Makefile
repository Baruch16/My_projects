CC = gcc

CFLAGS = -c
 

main : mainq2.o q2.o
	gcc -o main mainq2.o q2.o
	
mainq2.o : mainq2.c q2.c q2.h

q2.o : q2.c q2.h

run : main
	./main

clean :
	$(RM)  *.o main
