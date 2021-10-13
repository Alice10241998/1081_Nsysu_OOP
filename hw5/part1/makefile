CC = g++ -std=c++11

all: form dep

form: form.o
	$(CC) -o form form.o

form.o: form.cpp form.h
	$(CC) -c form.cpp

dep:
	$(CC) -MM form.cpp > dep

clean:
	rm -f *.o dep form
