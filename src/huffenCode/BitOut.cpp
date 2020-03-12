//
// Created by User on 2020-03-12.
//

#include "BitOut.h"
#include <iostream>


bool BitOut::writeBit(bool i) {
    if (count==8){
        writeBit(buffer);
        count=0;
        buffer=0;

    }
    buffer |= (i << (7 - count));
    return true;
}

BitOut::BitOut(std::string filename) {
    count=0;
    buffer=0;
    out.open(filename, std::ios::binary);
}

BitOut::~BitOut() {
    out.close();
}

bool BitOut::writeBit(int i) {
    if(i>1 || i <0){
        std::cerr <<"Only prints binary digits."<< std::endl;
        return false;
    } else{
        return writeBit(i==1);
    }}

bool BitOut::writeBit(char i) {
    if(i>1 || i <0){
        std::cerr <<"Only prints binary digits."<< std::endl;
        return false;
    } else{
        return writeBit(i==1);
    }
}
//do i need it it seem repetitive
void BitOut::close() {
    out.close();
}

void BitOut::fill() {
    while(count !=1){
        writeBit(true);
    }
}

bool BitOut::writeChar(char c) {
    if(out.is_open()){
        out.write(&c, sizeof(c));
    }
}
