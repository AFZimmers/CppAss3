#Makefile for Assignment 3
#Alex Zimmermann ZMMALE001

## Main Program

CC=g++
CCFLAGS=-std=c++11

SRC = src/huffmanCode/main.cpp \
        src/huffmanCode/huffmanTree.cpp \
        src/huffmanCode/huffmanTree.h \
        src/huffmanCode/huffmanNode.cpp \
        src/huffmanCode/huffmanNode.h \
        src/huffmanCode/huffenEncode.cpp \
        src/huffmanCode/huffenEncode.h \
        src/huffmanCode/huffenDecode.cpp \
        src/huffmanCode/huffenDecode.h \
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
