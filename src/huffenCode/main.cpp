//
// Created by User on 2020-03-05.
//

#include <iostream>
#include "huffmanEncode.h"


int main(int argc, char *argv[]){
    if(argc ==3){
        std::string input= std::string(argv[1]);
        std::string output= std::string(argv[2]);
        huffmanEncode code(input, output);
        code.encode();


    }
    return 0; 
}