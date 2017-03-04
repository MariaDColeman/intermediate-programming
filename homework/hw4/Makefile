# Lines starting with # are comments

# Some variable definitions to save typing later on
CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -pedantic -Wconversion -g

# Default (first) target -- fill this in
hw4: hw4.o dnasearch.o
        $(CC) -0 hw4 hw4.o dnasearch.o

# Links the test executable
test: test.o dnasearch.o
	$(CC) -o test test.o dnasearch.o

# Compiles hw4.c into an object file
hw4.o: hw4.c dnasearch.h
	$(CC) $(CFLAGS) -c hw4.c

# Compiles dnasearch.c into an object file
dnasearch.o: dnasearch.c dnasearch.h
	$(CC) $(CFLAGS) -c dnasearch.c

# Compiles test.c into an object file
test.o: test.c dnasearch.h
	$(CC) $(CFLAGS) -c test.c

# 'make clean' will remove intermediate & executable files
clean:
	rm -f *.o test hw4

