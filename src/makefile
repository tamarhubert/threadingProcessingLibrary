CC=gcc
CFLAGS=-I . -g -fPIC -Wall

OBJ=../obj

%.o: %.c
	$(CC) -c -o $(OBJ)/$@ $< $(CFLAGS)
	
make: threadingProcessingLibrary.o
