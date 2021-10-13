CC = g++

all: main main2 dep

main: stack.o main.o 
	$(CC) -o main main.o stack.o
main2: stack.o main2.o 
	$(CC) -o main2 main2.o stack.o 
main.o: main.cpp 
	$(CC) -c main.cpp
main2.o: main2.cpp 
	$(CC) -c main2.cpp 
stack.o: stack.cpp stack.h
	$(CC) -c stack.cpp 

dep:
	$(CC) -MM main.cpp main2.cpp > dep

clean:
	rm -f *.o dep main main2
	
