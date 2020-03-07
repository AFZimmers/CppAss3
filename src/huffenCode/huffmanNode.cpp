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

bool huffmanNode::isLeaf() { return (left== NULL && right ==NULL);}

int huffmanNode::getValue() const { return nodeValue;}

huffmanNode::huffmanNode(huffmanNode *l, huffmanNode *r) {
    left = shared_ptr<huffmanNode>(l);
    right = shared_ptr<huffmanNode>(r);

    for (int i = 0; i < left->chars.size(); ++i) {
        chars.push_back(left->chars[i]);
    }
    for (int j = 0; j < right->chars.size(); ++j) {
        chars.push_back(right->chars[j]);
    }

    nodeValue=left->nodeValue+right->nodeValue;
}

huffmanNode::huffmanNode(const huffmanNode &rhs) {
    chars=rhs.chars;
    nodeValue= rhs.nodeValue;
    codeBit= rhs.codeBit;
    if (rhs.right !=NULL) right= shared_ptr<huffmanNode>(new huffmanNode(*rhs.right));
    if (rhs.left !=NULL) left= shared_ptr<huffmanNode>(new huffmanNode(*rhs.left));
}

huffmanNode::huffmanNode(const huffmanNode &&rhs) {
    chars=move(rhs.chars);
    nodeValue=rhs.nodeValue;
    codeBit=rhs.codeBit;
    root=rhs.root;

    if (rhs.right !=NULL) right= move(rhs.right);
    if (rhs.left !=NULL) left= move(rhs.left);
}

huffmanNode &huffmanNode::operator=(const huffmanNode &rhs) {
    if(this!=&rhs){
        chars=rhs.chars;
        nodeValue=rhs.nodeValue;
        codeBit=rhs.codeBit;
        root = rhs.root;
        left.reset();
        right.reset();
        if (rhs.right !=NULL) right= move(rhs.right);
        if (rhs.left !=NULL) left= move(rhs.left);
    }
}