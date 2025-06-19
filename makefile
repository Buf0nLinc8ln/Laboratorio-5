CC = gcc
CFLAGS = -Iinclude
SRC =  src/lista.c


TARGET = main


all: $(TARGET)


$(TARGET): main.c $(SRC)
	$(CC) $(CFLAGS) main.c $(SRC) -o $(TARGET)


clean:
	rm -f *.o $(TARGET)

