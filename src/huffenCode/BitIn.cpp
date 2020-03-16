//
// Created by User on 2020-03-12.
//

#include <iostream>
#include "BitIn.h"


ZMMMALE001::BitIn::BitIn(const std::string& filename) {
    in.open(filename, std::ios::binary | std::ios::in);
    // std::cout<<in.get();
    count = 0;
    buffer = 0;
    status = true;
}

ZMMMALE001::BitIn::~BitIn() {
    in.close();
}

int ZMMMALE001::BitIn::readBit() {
    int out = 0;
    if (count == 0) {

        //std::cout<<in.get();
        if (!in.eof()) {
            char t = char(in.get());
            buffer = t; // replace the buffer
        }else {
            status = false;
            return 2;
        }
        count = 8;
    }
    out = 1 & (buffer >> (count - 1));
    count--;
    return out;
}

bool ZMMMALE001::BitIn::good() {
    return status;
}

void ZMMMALE001::BitIn::close() {
    in.close();
}