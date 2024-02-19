CC = gcc


main: mainq6.o q6func.o
	gcc -o main  mainq6.o q6func.o

main.o : mainq6.c  q6.h q6func.c

q6func.o : q6func.c q6.h

run : main
	./main
	
clean :
	$(RM) *.o ./main
