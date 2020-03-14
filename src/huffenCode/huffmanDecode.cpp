//
// Created by User on 2020-03-12.
//
#include <fstream>
#include <iostream>
#include "huffmanDecode.h"
#include "BitIn.h"

ZMMALE001::huffmanDecode::huffmanDecode(const std::string &inTxt, const std::string &inH, const std::string &out) {
    inStream=inTxt;
    inHeader=inH;
    outFile=out;
    setCodeTable();
}

ZMMALE001::huffmanDecode::~huffmanDecode() {
    codeTable.clear();
}

ZMMALE001::huffmanDecode::huffmanDecode(const ZMMALE001::huffmanDecode &rhs) {
    inStream=rhs.inStream;
    inHeader=rhs.inHeader;
    outFile=rhs.outFile;
    codeTable=rhs.codeTable;
}

ZMMALE001::huffmanDecode::huffmanDecode(const ZMMALE001::huffmanDecode &&rhs) {
    inStream=std::move(rhs.inStream);
    inHeader=std::move(rhs.inHeader);
    outFile=std::move(rhs.outFile);
    codeTable=std::move(rhs.codeTable);
}

ZMMALE001::huffmanDecode &ZMMALE001::huffmanDecode::operator=(const ZMMALE001::huffmanDecode &rhs) {
    if(this!=&rhs){
        inStream=rhs.inStream;
        inHeader=rhs.inHeader;
        outFile=rhs.outFile;
        codeTable=rhs.codeTable;
    }
    return *this;
}

bool ZMMALE001::huffmanDecode::decode() {
    ZMMMALE001::BitIn bitIn(inStream);
    std::ofstream out(outFile +".txt");
    std::string temp="";
    while(bitIn.good()) {
        temp += std::to_string(bitIn.readBit());
        if (codeTable.count(temp) != 0) {
            out << codeTable[temp];
            temp = "";
        }
    }
    out.close();
    bitIn.close();
    return false;
}

void ZMMALE001::huffmanDecode::setCodeTable() {
    std::ifstream in(inHeader);
    if (in.is_open()) {
        int numChars;
        in >> numChars;
        while (in.good()) {
            std::string c, code;
            in >> c;
            in >> code;
            if (c.compare("nn") == 0 || c.compare("nnn") == 0)
                c = "\n";
            if (c.compare("ss") == 0 || c.compare("sss") == 0)
                c = " ";
            codeTable[code] = c;
        }
    } else {
        std::cerr << "Header file could not be opened." << std::endl;
    }

}
