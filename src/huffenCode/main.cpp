//
// Created by User on 2020-03-05.
//

#include <iostream>
#include "huffmanEncode.h"
#include "huffmanDecode.h"


int main(int argc, char *argv[]){
    if(argc ==3){
        std::string input= std::string(argv[1]);
        std::string output= std::string(argv[2]);
        ZMMALE001::huffmanEncode code(input, output);
        code.encode();
        int freq=code.getNumFeq();
        int nodes=code.getNumNodes();
        int tc=code.getTotalChars();
        int ct=code.getNumbCodeTable();
        std::cout<<"Compression Complete.\nCompression Ration: "<<(code.getCompressionRation()*100)<<" %"<<std::endl;
    } else if(argc==4){
        std::string inputText=std::string(argv[1]);
        std::string inputHeader=std::string(argv[2]);
        std::string output=std::string(argv[3]);
        ZMMALE001::huffmanDecode decode(inputText,inputHeader, output);
        decode.decode();
    }
    return 0; 
}