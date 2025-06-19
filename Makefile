CC = gcc
CFLAGS = -Wall -Wextra -g
LIBS = -lm

SRCS = main.c src/ListasDoblementeEnlazadas.c src/stack.c src/lista.c
OBJS = $(SRCS:.c=.o)
EXEC = programa

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(EXEC) $(OBJS)
