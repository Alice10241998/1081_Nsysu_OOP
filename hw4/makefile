CC = g++
CFLAGS = -std=c++11 -c -Wall
SOURCES = main.cpp lexer.cpp token.cpp word.cpp type.cpp num.cpp real.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXE = main

all: $(SOURCES) $(EXE)

$(EXE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

dep:
	$(CC) -M *.cpp > .depend

clean:
	rm -f $(OBJECTS) $(EXE) .depend
