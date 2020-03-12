//
// Created by User on 2020-03-12.
//

#ifndef CPPASS3_BITOUT_H
#define CPPASS3_BITOUT_H

#include <fstream>
#include <bits/basic_string.h>

class BitOut {
private:
    std::ofstream  out;
    int count;
    char buffer;
    bool writeChar (char c);
public:
    BitOut(std::string filename);
    ~BitOut();

    bool writeBit(int i); // write int to file. int is a 1 or 0
    bool writeBit(char i);// write char to a file
    bool writeBit(bool i);// write a bit bool to file
    void close();         // close the bit stream
    void fill();          //flash the buff
};


#endif //CPPASS3_BITOUT_H
