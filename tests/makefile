CC=gcc
CFLAGS=-I . -g

OBJ=../obj

%.o: %.c
	$(CC) -c -o $(OBJ)/$@ $< $(CFLAGS)
	
make: threadingProcessingLibraryTests.o
	$(CC) -o $(OBJ)/threadingProcessingLibraryTests.bin $(OBJ)/threadingProcessingLibraryTests.o $(OBJ)/threadingProcessingLibrary.o $(CFLAGS) -lpthread
	
