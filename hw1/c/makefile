CC = gcc

all: main main2 dep

main: stack.o main.o 
	$(CC)  -o main main.o stack.o
main2: stack.o main2.o 
	$(CC)  -o main2 main2.o stack.o 
main.o: main.c
	$(CC)  -c main.c
main2.o: main2.c 
	$(CC) -c main2.c
stack.o: stack.c stack.h
	$(CC)  -c stack.c 

dep:
	$(CC) -MM main.c main2.c > dep

clean:
	rm -f *.o dep main main2
