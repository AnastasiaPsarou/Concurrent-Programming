CC = gcc
CFLAGS = -Wall -g
OBJ = 3.o library.o

all: $(OBJ)
	$(CC) $(OBJ) -o all -lpthread

3.o: 3.c library.h
	$(CC) $(CFLAGS) -c 3.c -lpthread

library.o: library.c library.h
	$(CC) $(CFLAGS) -c library.c -lpthread
