CC = gcc

main: main-hash.o HASH-1.o

main-hash.o : main-hash.c  hash.h HASH-1.c

HASH-1.o : HASH-1.c hash.h

run : main
	./main
	
clean :
	$(RM) *.o ./main
