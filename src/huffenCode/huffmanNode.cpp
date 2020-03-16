//
// Created by User on 2020-03-05.
//
#include <memory>
#include "huffmanNode.h"
using namespace std;
huffmanNode::huffmanNode(char c, int count) {
    chars.push_back(c);
    nodeValue=count;
    left.reset();
    right.reset();
}

huffmanNode::~huffmanNode() {
    nodeValue=0;
    chars.clear();
}

bool huffmanNode::isLeaf() { return (left== nullptr && right ==nullptr);}

int huffmanNode::getValue() const { return nodeValue;}

huffmanNode::huffmanNode(huffmanNode *l, huffmanNode *r) {
    left = shared_ptr<huffmanNode>(l);
    right = shared_ptr<huffmanNode>(r);

    for (char i : left->chars) {
        chars.push_back(i);
    }
    for (char j : right->chars) {
        chars.push_back(j);
    }

    nodeValue=left->nodeValue+right->nodeValue;
}

huffmanNode::huffmanNode(const huffmanNode &rhs) {
    chars=rhs.chars;
    nodeValue= rhs.nodeValue;
    codeBit= rhs.codeBit;
    if (rhs.right !=nullptr) right= shared_ptr<huffmanNode>(new huffmanNode(*rhs.right));
    if (rhs.left !=nullptr) left= shared_ptr<huffmanNode>(new huffmanNode(*rhs.left));
}

huffmanNode::huffmanNode(const huffmanNode &&rhs) {
    chars=move(rhs.chars);
    nodeValue=rhs.nodeValue;
    codeBit=rhs.codeBit;
    root=rhs.root;

    if (rhs.right !=nullptr) right= move(rhs.right);
    if (rhs.left !=nullptr) left= move(rhs.left);
}

huffmanNode &huffmanNode::operator=(const huffmanNode &rhs) {
    if(this!=&rhs){
        chars=rhs.chars;
        nodeValue=rhs.nodeValue;
        codeBit=rhs.codeBit;
        root = rhs.root;
        left.reset();
        right.reset();
        if (rhs.right !=nullptr) right= move(rhs.right);
        if (rhs.left !=nullptr) left= move(rhs.left);
    }
}