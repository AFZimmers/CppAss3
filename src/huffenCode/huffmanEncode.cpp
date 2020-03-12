//
// Created by User on 2020-03-12.
//
#include <fstream>
#include <iostream>

#include "huffmanEncode.h"
#include "BitOut.h"

bool ZMMALE001::huffmanEncode::buildFeqTable() {
    std::ifstream in(infile);
    if(in.is_open()){
        while(in.good()){
            totalInputChars++;
            freqMap[char(in.get())]++;
        }
        in.close();
        freqMap.erase(char(-1));
        return true;
    } else{
        in.close();
        std::cerr<<"input file could not be accessed "<<std::endl;
        return false;
    }
}

bool ZMMALE001::huffmanEncode::buildTree() {
    tree= huffmanTree(freqMap);
    return tree.successful();
}

void ZMMALE001::huffmanEncode::buildCodeTable() {
    for(int c=0; c<tree.root->chars.size();c++){
        huffCode code;
        buildCode(tree.root,tree.root->chars[c],code);
        codeTable[tree.root->chars[c]]=code;
    }

}

void ZMMALE001::huffmanEncode::encodeTxt() {
// export the code table to a header file
    std::string h(outfile + ".hdr");
    std::ofstream header(h);
    if (header.is_open()) {
        header << codeTable.size() << std::endl;
        std::unordered_map<char, huffCode>::iterator it;
        for (it = codeTable.begin(); it != codeTable.end(); it++) {
            if (it->first == '\n'){
                header << "nn" << " ";
            }
            else if (it->first == ' '){
                header << "ss" << " ";
            }else {
                header << it->first << " ";
            }
            for (int x = 0; x < it->second.size(); x++) {
                header << it->second[x];
            }
            header << std::endl;
        }
    } else {
        std::cerr << "Could not write header file. something went wrong." << std::endl;
        header.close();
        return;
    }
    header.close();
    // cycle through the text file and build a new buffer using the code table
    std::ifstream in(infile);
    std::ofstream out(outfile+".hufftext");
    BitOut bitOut(outfile+".huffstrm");

    if (in.is_open() && out.is_open()) {
        while (in.good()) {
            char c = char(in.get());
            for (int i = 0; i < codeTable[c].size(); i++) {
                bool v = codeTable[c][i] == 1;
                out << v;
                bitOut.writeBit(v);
                totalOutputBits++;
            }
        }
        bitOut.fill();
        bitOut.close();
        out.close();
        in.close();
        compressionRatio = (totalOutputBits*1.0/8.0)/(totalInputChars*1.0);
    } else {
        std::cerr << "Files could not be opened." << std::endl;
        bitOut.close();
        out.close();
        in.close();
    }
}

ZMMALE001::huffmanEncode::~huffmanEncode() {
    freqMap.clear();
}

ZMMALE001::huffmanEncode::huffmanEncode(const std::string &in, const std::string &out) {
    infile=in;
    outfile=out;
}

ZMMALE001::huffmanEncode::huffmanEncode(const ZMMALE001::huffmanEncode &rhs) {
    tree=rhs.tree;
    infile=rhs.infile;
    outfile=rhs.outfile;
    freqMap=rhs.freqMap;
    codeTable=rhs.codeTable;
}

ZMMALE001::huffmanEncode::huffmanEncode(const ZMMALE001::huffmanEncode &&rhs) {
    tree=std::move(rhs.tree);
    infile=std::move(rhs.infile);
    outfile=std::move(rhs.outfile);
    freqMap=std::move(rhs.freqMap);
    codeTable=std::move(rhs.codeTable);
}

ZMMALE001::huffmanEncode &ZMMALE001::huffmanEncode::operator=(const ZMMALE001::huffmanEncode &rhs) {
    if(this!=&rhs){
        tree=rhs.tree;
        infile=rhs.infile;
        outfile=rhs.outfile;
        freqMap=rhs.freqMap;
        codeTable=rhs.codeTable;
    }
    return *this;
}

bool ZMMALE001::huffmanEncode::encode() {
    if(buildFeqTable() && buildTree()){
        buildCodeTable();
        encodeTxt();
        return true;
    }
    return false;
}

void ZMMALE001::huffmanEncode::buildCode(shared_ptr<huffmanNode> &node, char &character, ZMMALE001::huffCode &code) {
    if(node == NULL){
        return;
    }
    if(node->root){
        buildCode(node->left,character,code);
        buildCode(node->right,character,code);
    } else{
        for(int c=0;c<node->chars.size();c++){
            code.push_back(node->codeBit);
            buildCode(node->left,character,code);
            buildCode(node->right,character,code);
            return;
        }
        return;
    }

}

int ZMMALE001::huffmanEncode::getNumFeq() {
    return freqMap.size();
}

int ZMMALE001::huffmanEncode::getCount(char c) {
    return freqMap[c];
}

int ZMMALE001::huffmanEncode::getNumbCodeTable() {
    return codeTable.size()-1;
}

int ZMMALE001::huffmanEncode::getNumNodes() {
    return tree.getNumNodes();
}

int ZMMALE001::huffmanEncode::getTotalChars() {
    return tree.getTotalChars();
}

int ZMMALE001::huffmanEncode::getRootValue() {
    return tree.root->nodeValue;
}

double ZMMALE001::huffmanEncode::GetComperrsionRatio() {
    return compressionRatio;
}
