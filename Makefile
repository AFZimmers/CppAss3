#Makefile for Assignment 3
#Alex Zimmermann ZMMALE001

## Main Program

CC=g++
CCFLAGS=-std=c++11

SRC = src/huffmanCode/main.cpp \
        src/huffmanCode/HuffmanTree.cpp \
        src/huffmanCode/HuffmanTree.h \
        src/huffmanCode/HuffmanNode.cpp \
        src/huffmanCode/HuffmanNode.h \
        src/huffmanCode/HuffenEncode.cpp \
        src/huffmanCode/HuffenEncode.h \
        src/huffmanCode/HuffenDecode.cpp \
        src/huffmanCode/HuffenDecode.h \
        src/huffmanCode/BitIn.cpp \
        src/huffmanCode/BitIn.h \
        src/huffmanCode/BitOut.cpp \
        src/huffmanCode/BitOut.h \

OBJ = $(SRC:.cpp=.o)

PROG = huffmanCode

$(PROG) : $(OBJ)
	$(CC) $(CCFLAGS) $(SRC) -o huffmanCode

.cpp.o:
	$(CC) $(CCFLAGS) -c $<

depend:
	$(CC) -M $(SRC) > incl.defs

# clean
clean:
	rm -f *.o
	rm -f huffmanCode
