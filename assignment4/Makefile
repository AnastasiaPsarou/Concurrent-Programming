CC = gcc
CFLAGS = -Wall -g
OBJ = 1.o library.o

all: $(OBJ)
	$(CC) $(OBJ) -o all -lpthread

1.o: 1.c library.h
	$(CC) $(CFLAGS) -c 1.c -lpthread

library.o: library.c library.h
	$(CC) $(CFLAGS) -c library.c -lpthread
