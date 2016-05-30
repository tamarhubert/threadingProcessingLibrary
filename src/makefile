CC=gcc
CFLAGS=-I . -g

OBJ=../obj

%.o: %.c
	$(CC) -c -o $(OBJ)/$@ $< $(CFLAGS)
	
make: threadingProcessingLibrary.o
