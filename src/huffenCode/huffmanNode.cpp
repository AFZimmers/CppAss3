//
// Created by User on 2020-03-05.
//

#include "huffmanNode.h"

huffmanNode::huffmanNode(char c, int count) {
    chars.push_back(c);
    nodeValue=count;
    left.reset();
    right.reset()
}

huffmanNode::~huffmanNode() {
    nodeValue=0;
    chars.clear();
}

bool huffmanNode::isLeaf() { return (left== NULL && right ==Null);}

int huffmanNode::getValue() const { return nodeValue};}

huffmanNode::huffmanNode(huffmanNode *left, huffmanNode *right) {
    left = share_ptr<huffmanNode(this->left);
    right = share_ptr<huffmanNode(this->right);

    for (int i = 0; i < left->chars.size(); ++i) {
        chars.push_back(left->chars[i]);
    }
    for (int j = 0; j < right->chars.size(); ++j) {
        chars.push_back(right->chars.size[j]);
    }

    nodeValue=left->nodeValue+right->nodeValue;
}

huffmanNode::huffmanNode(const huffmanNode &rhs) {
    chars=rhs.chars;
    nodeValue= rhs.nodeValue;
    codeBit= rhs.codeBit;
    if (rhs.right !=NULL) right= share_ptr<huffmanNode>(new huffmanNode(*rhs.right));
    if (rhs.left !=NULL) left= share_ptr<huffmanNode>(new huffmanNode(*rhs.left));
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