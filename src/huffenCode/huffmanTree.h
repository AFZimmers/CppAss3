//
// Created by User on 2020-03-05.
//

#ifndef ASSIGNMENT_3_HUFFMANTREE_H
#define ASSIGNMENT_3_HUFFMANTREE_H

#include <memory>
#include <queue>
#include <unordered_map>
#include "huffmanNode.h"

using namespace std;

/**
 * comapre node  function
 */
struct CompareNode{
    bool operator()(huffmanNode* const &p1,huffmanNode* const &p2){
        if(p1->getValue()==p2->getValue()){
            return p1->chars[0] >p1->chars[0];
        }
        else{
            return p1->getValue()>p2->getValue();
        }
    }
};

class huffmanTree{
private:
    bool success;
    priority_queue<huffmanNode *, vector<huffmanNode*>, CompareNode> queue;
    int countNode(shared_ptr<huffmanNode> root);

public:
    shared_ptr<huffmanNode> root; // Root node of the tree
    huffmanTree(){};
    huffmanTree(const unordered_map<char, int> &freqMap); //Constructor which creates the tree, it cycles through the frequency table and creates nodes for each character.

    ~huffmanTree();
    huffmanTree(const huffmanTree & rhs); // copy constructor
    huffmanTree(const huffmanTree&& rhs); // move constructor
    huffmanTree &operator =(const huffmanTree& rhs); // copy assignment operator

    void createTree(); // cycles through the priority ques and creates the tree from the leaves to the root.
    bool successful(); // check if tree build was successful

};
#endif //ASSIGNMENT_3_HUFFMANTREE_H
