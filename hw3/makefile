CC = g++ -std=c++11

all: main dep

main: Complex.o main.o 
	$(CC) -o main Complex.o main.o

Complex.o: Complex.cpp Complex.h
	$(CC) -c Complex.cpp
 
main.o: main.cpp 
	$(CC) -c main.cpp

dep:
	$(CC) -MM main.cpp > dep

clean:
	rm -f *.o dep main
	
