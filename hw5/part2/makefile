CC = g++ -std=c++11

all: vector dep

vector: vector.o trace.o 
	$(CC) -o vector vector.o trace.o

vector.o: vector.cpp trace.cpp
	$(CC) -c vector.cpp

dep:
	$(CC) -MM vector.cpp > dep

clean:
	rm -f *.o dep vector
	
