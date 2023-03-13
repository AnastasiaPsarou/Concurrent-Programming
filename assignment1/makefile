CC = gcc
CFLAGS = -Wall -g
OBJ = main.o erg1.o


all: $(OBJ)
	$(CC) $(OBJ) -o all -lpthread
	
main.o: main.c erg1.h
	$(CC) $(CFLAGS) -c main.c -lpthread
	
erg1.o: erg1.c erg1.h
	$(CC) $(CFLAGS) -c erg1.c -lpthread
