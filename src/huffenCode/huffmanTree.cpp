//
// Created by User on 2020-03-05.
//

#include "huffmanTree.h"
using namespace std;

huffmanTree::huffmanTree(const unordered_map<char, int> &freqMap) {
    success= false;
    unordered_map<char,int>::const_iterator iter;
    for(iter=freqMap.begin(); iter!=freqMap.end();iter++){
        //skip the -1 from end of line
        if(int(iter->first)==-1){
            continue;
        }
        queue.push(new huffmanNode(char(iter->first),int(iter->second)));//push new node
    }
    createTree();
}

void huffmanTree::createTree() {
    while(queue.size()>1){
        huffmanNode*l=queue.top();
        queue.pop();
        huffmanNode*r=queue.top();
        queue.pop();
        l->codeBit=false;
        r->codeBit= true;
        huffmanNode* node = new huffmanNode(l,r);
        queue.push(node);
    }
    root=shared_ptr<huffmanNode>(queue.top());
    root->root=true;
    queue.pop();
    if(queue.empty()){
        success=true;
    }
}

huffmanTree::~huffmanTree() {
    root.reset();
    if(!queue.empty()){
        for (int i=0;i<queue.size();i++){
            delete queue.top();
            queue.pop();
        }
    }
}

bool huffmanTree::successful() {
    return success;
}

huffmanTree::huffmanTree(const huffmanTree &rhs) {
    root =rhs.root;
    queue=rhs.queue;
    success=rhs.success;
}
huffmanTree::huffmanTree(const huffmanTree &&rhs) {
    root =move(rhs.root);
    queue=move(rhs.queue);
    success=move(rhs.success);
}

huffmanTree & huffmanTree::operator=(const huffmanTree &rhs) {
    if(this!=&rhs){
        root =rhs.root;
        queue=rhs.queue;
        success=rhs.success;
    }
    return *this;
}

int huffmanTree::countNode(shared_ptr <huffmanNode> root) {
    if(root==NULL){
        return 0;
    }
    else{
        int count=1;
        count+=countNode(root->left);
        count+=countNode(root->right);
        return count;
    }
}

int huffmanTree::getNumNodes() {
    return countNode(root);
}
int huffmanTree::getTotalChars() {
    return root->chars.size();
}