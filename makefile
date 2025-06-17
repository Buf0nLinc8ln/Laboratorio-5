CC = gcc
CFLAGS = -Wall -g
OBJS = main.o stack.o
EXEC = main

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

main.o: main.c stack.h
stack.o: stack.c stack.h

clean:
	rm -f *.o $(EXEC)
