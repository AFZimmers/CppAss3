//
// Created by User on 2020-03-05.
//

#ifndef ASSIGNMENT_3_HUFFMANNODE_H
#define ASSIGNMENT_3_HUFFMANNODE_H

#include <vector>
#include <memory>

using namespace std;
class huffmanNode{

private:

public:
    vector<char> chars; // chars represented by the node
    int nodeValue;      // Value of left, right child
    shared_ptr<huffmanNode> left,right;
    bool codeBit;       //tells if 0 it is on the left, 1 if it is on the right
    bool root = false;

    huffmanNode(char c, int count);// creates a new node using the given characters.
    ~huffmanNode();
    huffmanNode(huffmanNode * left, huffmanNode * right); // creates a new node from the 2 nodes left and right.
    huffmanNode(const huffmanNode& rhs);
    huffmanNode(const huffmanNode&& rhs);
    huffmanNode &operator =(const huffmanNode(& rhs));

    bool isLeaf();
    int getValue() const ;

};
#endif //ASSIGNMENT_3_HUFFMANNODE_H
