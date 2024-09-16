

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <iostream>
    using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int item) {
        key = item;
        left = nullptr;
        right = nullptr;
    }
};


class BinarySearchTree {
public:
    // A utility function to insert a new node with
    // the given key
    Node* insert(Node* node, int key);
    // A utility function to do inorder tree traversal
    void inorder(Node* root);
};



#endif //BINARYSEARCHTREE_H
