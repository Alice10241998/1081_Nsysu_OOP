CC = g++ -std=c++11

all: mytar dep

mytar: mytar.o main.o 
	$(CC) -o mytar mytar.o main.o

mytar.o: mytar.cpp mytar.h
	$(CC) -c mytar.cpp
 
main.o: main.cpp 
	$(CC) -c main.cpp

dep:
	$(CC) -MM main.cpp > dep

clean:
	rm -f *.o dep mytar
	
