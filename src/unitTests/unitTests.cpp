//
// Created by User on 2020-03-07.
//
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "../huffmanCode/huffmanEncode.h"

// text file which includes all the letters of the alphabet, spaces, comma and fullstop.
TEST_CASE("Check if the freq map has the right number of elements", "[FrequencyMapElements]") {

    ZMMALE001::huffmanEncode code("../text/test1.txt", "outTest");
    ZMMALE001::huffmanEncode code2("../text/test2.txt", "outTest");
    code.encode();
    code2.encode();

    REQUIRE(code.getNumFreq() == 36); // alphabet + fullstop + space + comma
    REQUIRE(code2.getNumFreq() == 37);
}

TEST_CASE("Check if the counts in unordered map (frequency table) are correct", "[FrequencyTableCounts]") {

    ZMMALE001::huffmanEncode code("../text/test1.txt", "outTest");
    ZMMALE001::huffmanEncode code2("../text/test2.txt", "outTest");
    code.encode();
    code2.encode();

    REQUIRE(code.getCount('m') == 1);
    REQUIRE(code.getCount(' ') == 18);
    REQUIRE(code.getCount('c') == 4);
    REQUIRE(code2.getCount('b') == 3);
    REQUIRE(code2.getCount('a') == 10);
    REQUIRE(code2.getCount('z') == 2);
}

TEST_CASE("Check if the Huffman tree has the correct number of nodes", "[NodeNumber]") {

    ZMMALE001::huffmanEncode code("../text/test1.txt", "outTest");
    ZMMALE001::huffmanEncode code2("../text/test2.txt", "outTest");
    code.encode();
    code2.encode();

    REQUIRE( code.getNumNodes() == 77);
    REQUIRE( code2.getNumNodes() == 73);

}
//todo look at the right count
TEST_CASE("Check if the root of the Huffman Tree root has the correct number of characters present in the text", "[Characters]") {

    ZMMALE001::huffmanEncode code("../text/test1.txt", "outTest");
    ZMMALE001::huffmanEncode code2("../text/test2.txt", "outTest");
    code.encode();
    code2.encode();

    REQUIRE( code.getTotalChars() == 29); // corresponds to number of elements in freq table
    REQUIRE( code2.getTotalChars() == 23);

}

TEST_CASE("Check if the Huffman tree root has the correct count", "[RootValue]") {

    ZMMALE001::huffmanEncode code("../text/test1.txt", "outTest");
    ZMMALE001::huffmanEncode code2("../text/test2.txt", "outTest");
    code.encode();
    code2.encode();

    REQUIRE( code.getRootValue() == 107);
    REQUIRE( code2.getRootValue() == 158);

}

TEST_CASE("Check if coding table has the correct number of encoded characters.", "[CodeTable]") {


    ZMMALE001::huffmanEncode code("../text/test1.txt", "outTest");
    ZMMALE001::huffmanEncode code2("../text/test2.txt", "outTest");
    code.encode();
    code2.encode();

    REQUIRE( code.getNumCodeTable() == 29);
    REQUIRE( code2.getNumCodeTable() == 23);
}

