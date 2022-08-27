#ifndef BSTNODE_H
#define BSTNODE_H

template <typename keyType>
class BSTNode{
    keyType keyVal;
    BSTNode* leftChild;
    BSTNode* rightChild;

public:
    BSTNode(keyType k=NULL,BSTNode<keyType>* l=NULL,BSTNode<keyType>* r=NULL){
        keyVal = k;
        leftChild = l;
        rightChild = r;
    }

    keyType key(){return keyVal;}
    BSTNode<keyType>* left(){return leftChild;}
    BSTNode<keyType>* right(){return rightChild;}

    void setKey(const keyType& k){keyVal = k;}
    void setLeft(BSTNode<keyType>* l){leftChild = l;}
    void setRight(BSTNode<keyType>* r){rightChild = r;}

    bool isLeaf(){return leftChild==NULL && rightChild==NULL;}
};

#endif