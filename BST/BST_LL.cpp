#include <iostream>
#include <cstring>
#include "BSTNode.h"
using namespace std;

template <typename keyType>
class BST_LL{
    BSTNode<keyType>* root;
    int nodeCount;

    void clearHelp(BSTNode<keyType>* node){
        // Deletes left and right subtree, then deletes itself
        if(node == NULL) return;
        clearHelp(node->left());
        clearHelp(node->right());
        delete node;
    }

    BSTNode<keyType>* insertHelp(BSTNode<keyType>* currNode, const keyType& key){
        // If at the correct place, creates new leaf node and returns it
        // Enters the suitable subtree otherwise
        if(currNode == NULL)
            return new BSTNode<keyType>(key);
        if(key < currNode->key())
            currNode->setLeft(insertHelp(currNode->left(),key));
        else
            currNode->setRight(insertHelp(currNode->right(),key));
        return currNode;
    }

    bool findHelp(BSTNode<keyType>* currNode, const keyType& query){
        if(currNode == NULL) return false;
        if(currNode->key() == query)
            return true;
        else if(query < currNode->key())
            return findHelp(currNode->left(), query);
        else
            return findHelp(currNode->right(), query);
    }

    void printHelp(BSTNode<keyType>* currNode){
        // If not a leaf node, prints own key and then enters its subtrees
        cout<<"(";
        if(currNode != NULL){
            cout<<currNode->key();
            if(!currNode->isLeaf()){
                printHelp(currNode->left());
                printHelp(currNode->right());
            }
        }
        cout<<")";
    }

    BSTNode<keyType>* removeHelp(BSTNode<keyType>* currNode, const keyType& query){
        if(currNode == NULL)
            return NULL;
        if(query < currNode->key())
            currNode->setLeft(removeHelp(currNode->left(), query));
        else if(query > currNode->key())
            currNode->setRight(removeHelp(currNode->right(),query));

        else{
            BSTNode<keyType>* temp = currNode;
            // Promotes right subtree to own place
            if(currNode->left() == NULL){
                currNode = currNode->right();
                delete temp;
            }
            // Promotes left subtree to own place
            else if(currNode->right() == NULL){
                currNode = currNode->left();
                delete temp;
            }

            //Replaces the node's key with the max element of its left subtree
            else{
                BSTNode<keyType>* replacor = getMax(currNode->left());
                currNode->setKey(replacor->key());
                currNode->setLeft(deleteMax(currNode->left()));
                delete replacor;
            }
        }
        return currNode;
    }

    BSTNode<keyType>* getMax(BSTNode<keyType>* currNode){
        if(currNode->right() == NULL)
            return currNode;
        return getMax(currNode->right());
    }

    BSTNode<keyType>* deleteMax(BSTNode<keyType>* currNode){
        // Promotes the left subtree of the node with highest key, thus removing it from the BST
        if(currNode->right() == NULL)
            return currNode->left();
        currNode->setRight(deleteMax(currNode->right()));
        return currNode;
    }

    // void visit(BSTNode<keyType>* node){
    //     cout<<node->key()<<" ";
    // }

    void preorder(BSTNode<keyType>* node, keyType* arr, int& index){
        if(node == NULL) return;
        arr[index++] = node->key();
        preorder(node->left(), arr, index);
        preorder(node->right(), arr, index);
    }

    void inorder(BSTNode<keyType>* node, keyType* arr, int& index){
        if(node == NULL) return;
        inorder(node->left(), arr, index);
        arr[index++] = node->key();
        inorder(node->right(), arr, index);
    }

    void postorder(BSTNode<keyType>* node, keyType* arr, int& index){
        if(node == NULL) return;
        postorder(node->left(), arr, index);
        postorder(node->right(), arr, index);
        arr[index++] = node->key();
    }

public:
    BST_LL(){
        root = NULL;
        nodeCount = 0;
    }

    ~BST_LL(){clearHelp(root);}
    void clear(){
        clearHelp(root);
        root = NULL;
        nodeCount = 0;
    }

    void insert(const keyType& key){
        root = insertHelp(root, key);
        nodeCount++;
    }

    bool find(const keyType& query){
        return findHelp(root, query);
    }

    int size(){
        return nodeCount;
    }

    void print(){
        if(root == NULL) return;
        cout<<root->key();
        if(!root->isLeaf()){
            printHelp(root->left());
            printHelp(root->right());
        }
        cout<<"\n";
    }

    void remove(const keyType& query){
        bool flag = findHelp(root, query);
        if(!flag)
            throw "Invalid Operation";
        root = removeHelp(root, query);
        nodeCount--;
    }

    keyType* traverse(const char* type){
        // Creates a new array, loads it with traversal results and returns it
        keyType* arr = new keyType[nodeCount];
        int index = 0;
        if(!strcmp(type, "Pre"))
            preorder(root, arr, index);
        else if(!strcmp(type, "In"))
            inorder(root, arr, index);
        else if(!strcmp(type, "Post"))
            postorder(root, arr, index);
        return arr;
    }
};