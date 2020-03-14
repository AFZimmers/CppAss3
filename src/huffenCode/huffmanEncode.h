//
// Created by User on 2020-03-12.
//

#ifndef CPPASS3_HUFFMANENCODE_H
#define CPPASS3_HUFFMANENCODE_H

#include <string>
#include <exception>
#include <unordered_map>
#include "huffmanTree.h"

namespace  ZMMALE001 {
    typedef std::vector<bool> huffCode;


    class huffmanEncode {
    private:
        int totalInputChars = 0;
        int totalOutputBits = 0;
        double compressionRatio = 0;

        huffmanTree tree;
        std::string infile, outfile;
        std::unordered_map<char, int> freqMap;
        std::unordered_map<char, huffCode> codeTable;

        bool buildFeqTable();   //read input file and build freq table
        bool buildTree();       //build the huffmanTree from the freq table
        void buildCodeTable();  //from the huffmanTree build the code table
        void encodeTxt();       //create output buffer for the text using the code from the code table

    public:
    huffmanEncode();
    ~huffmanEncode();
    huffmanEncode(const std::string& inFile, const std::string& outfile);   //constructor to create a new object
    huffmanEncode(const huffmanEncode& rhs);                                //copy constructor
    huffmanEncode(const huffmanEncode&& rhs);                               //mover constructor
    huffmanEncode& operator=(const huffmanEncode& rhs);                     //copy assignment constructor

    bool encode();
    void buildCode(shared_ptr<huffmanNode>& node, char& character, huffCode& code);

    //debugging
    int getNumFeq();
    int getCount(char c);
    int getNumbCodeTable();
    int getNumNodes();
    int getTotalChars();
    int getRootValue();
    double getCompressionRation();

    };

}
#endif //CPPASS3_HUFFMANENCODE_H
