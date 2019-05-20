CC=gcc
LD=gcc

CFLAGS=-Wall -Werror -g -O0
LDFLAGS=-lm


EXEC=main
SRC=$(wildcard *.c)
OBJECTS=$(SRC:.c=.o)

.PHONY: target clean realclean

target:$(EXEC)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

$(EXEC): $(OBJECTS)
	$(LD) -o $(EXEC) $(OBJECTS) $(LDFLAGS)
	
clean:
	rm -f *.o core
realclean: clean
	rm -f *~
