CC=g++
LD=g++

CFLAGS=-Wall -g -O0
LDFLAGS=-lm


EXEC=main
SRC=$(wildcard *.cpp)
OBJECTS=$(SRC:.cpp=.o)

.PHONY: target clean realclean

target:$(EXEC)

%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

$(EXEC): $(OBJECTS)
	$(LD) -o $(EXEC) $(OBJECTS) $(LDFLAGS)

clean:
	rm -f *.o core
realclean: clean
	rm -f *~
