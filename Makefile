#Makefile for Assignment 3
#Alex Zimmermann ZMMALE001

## Main Program

CC=g++
CCFLAGS=-std=c++14

SRC = src/huffencode/main.cpp \
        src/huffencode/HuffmanTree.cpp \
        src/huffencode/HuffmanTree.h \
        src/huffencode/HuffmanNode.cpp \
        src/huffencode/HuffmanNode.h \
        src/huffencode/HuffenEncode.cpp \
        src/huffencode/HuffenEncode.h \
        src/huffencode/HuffenDecode.cpp \
        src/huffencode/HuffenDecode.h \
        src/huffencode/BitIn.cpp \
        src/huffencode/BitIn.h \
        src/huffencode/BitOut.cpp \
        src/huffencode/BitOut.h \

OBJ = $(SRC:.cpp=.o)

PROG = huffencode

$(PROG) : $(OBJ)
	$(CC) $(CCFLAGS) $(SRC) -o huffencode

.cpp.o:
	$(CC) $(CCFLAGS) -c $<

depend:
	$(CC) -M $(SRC) > incl.defs

# clean
clean:
	rm -f *.o
	rm -f huffencode
