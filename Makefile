CC = gcc
CFLAGS = -Wall -Wextra
LIBS = -lm

SRCS = main.c ListasDoblementeEnlazadas.c
OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)

programa: $(OBJS)
    $(CC) $(CFLAGS) -o programa $(OBJS) $(LIBS)

%.o: %.c
    $(CC) $(CFLAGS) -c -o $@ $<

clean:
    rm -f programa $(OBJS) $(DEPS)

-include $(DEPS)