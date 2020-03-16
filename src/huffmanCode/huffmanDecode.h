//
// Created by User on 2020-03-12.
//

#ifndef CPPASS3_HUFFMANDECODE_H
#define CPPASS3_HUFFMANDECODE_H

#include <string>
#include "huffmanEncode.h"

namespace ZMMALE001 {
    class huffmanDecode {
    private:
        std::string inStream, inHeader, outFile;
        std::unordered_map<std::string,std::string>codeTable;
        void setCodeTable();

    public:
        huffmanDecode(const std::string& inTxt, const std::string& inHeader, const std::string& out);
        ~huffmanDecode();
        huffmanDecode(const huffmanDecode& rhs);
        huffmanDecode(const huffmanDecode&& rhs);
        huffmanDecode& operator=(const huffmanDecode& rhs);

        bool decode();// starts the decoding

    };
}


#endif //CPPASS3_HUFFMANDECODE_H
