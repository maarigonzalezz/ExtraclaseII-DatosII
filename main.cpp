#include <iostream>
#include "Sorters.h"
#include "ASLLSearch.h"
#include "BinarySearchTree.h"

using namespace std;
int main()
{
    cout << "Hello, World!" << endl;

    BinarySearchTree bst;
    Node* root = new Node(50);
    root = bst.insert(root, 30);
    root = bst.insert(root, 20);
    root = bst.insert(root, 40);
    root = bst.insert(root, 70);
    root = bst.insert(root, 60);
    root = bst.insert(root, 80);

    // Print inorder traversal of the BST
    bst.inorder(root);
    
    return 0;
}
