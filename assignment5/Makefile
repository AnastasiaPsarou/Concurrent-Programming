CC = gcc
CFLAGS = -Wall -g
OBJ = 2.o library.o

all: $(OBJ)
	$(CC) $(OBJ) -o all -lpthread

2.o: 2.c library.h
	$(CC) $(CFLAGS) -c 2.c -lpthread

library.o: library.c library.h
	$(CC) $(CFLAGS) -c library.c -lpthread
