CC = gcc
CFLAGS = -Wall -g
OBJ = 4.o library.o

all: $(OBJ)
	$(CC) $(OBJ) -o all -lpthread

4.o: 4.c library.h
	$(CC) $(CFLAGS) -c 4.c -lpthread

library.o: library.c library.h
	$(CC) $(CFLAGS) -c library.c -lpthread
