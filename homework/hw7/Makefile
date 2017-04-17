#Lines starting with # are comments

# Some variable definitions to save typing later on in this file
CC = g++
CONSERVATIVE_FLAGS = -std=c++11 -Wall -Wextra -pedantic
DEBUGGING_FLAGS = -g
CFLAGS = $(CONSERVATIVE_FLAGS) $(DEBUGGING_FLAGS)

# Links main executable file hw7
hw7a: hw7a.o fileIO.o
	$(CC) -o hw7a hw7a.o fileIO.o

hw7b: hw7b.o fileIO.o
	$(CC) -o hw7b hw7b.o fileIO.o

test_hw7a: test_hw7a.o fileIO.o
	$(CC) -o test_hw7a test_hw7a.o fileIO.o

test_hw7b: test_hw7b.o fileIO.o
	$(CC) -o test_hw7b test_hw7b.o fileIO.o


hw7a.o: hw7a.cpp fileIO.o
	$(CC) $(CFLAGS) -c hw7a.cpp

fileIO.o: fileIO.cpp fileIO.hpp
	$(CC) $(CFLAGS) -c fileIO.cpp

hw7b.o: hw7b.cpp fileIO.o
	$(CC) $(CFLAGS) -c hw7b.cpp

test_hw7a.o: test_hw7a.cpp fileIO.o
	$(CC) $(CFLAGS) -c test_hw7a.cpp

test_hw7b.o: test_hw7b.cpp fileIO.o
	$(CC) $(CFLAGS) -c test_hw7b.cpp


# 'make clean' will remove intermediate/executible files
clean:
	rm -f *.o hw7a

