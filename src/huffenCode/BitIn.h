//
// Created by User on 2020-03-12.
//

#ifndef CPPASS3_BITIN_H
#define CPPASS3_BITIN_H

#include <fstream>

namespace ZMMMALE001 {
    class BitIn {
    private:
        std::ifstream in;
        int count;
        char buffer;
    public:
        bool status;

        BitIn(std::string filename);
        BitIn(){};
        ~BitIn();

        int readBit();
        void close();
        bool good();

    };
}


#endif //CPPASS3_BITIN_H
