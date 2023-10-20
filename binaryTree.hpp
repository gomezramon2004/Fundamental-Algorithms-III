#pragma once
#include "node.cpp"
#include <vector>

class BinaryTree {
public:
    Node* root;
    std::vector<int> orderedVector;

    BinaryTree();
    BinaryTree(int size);

    void insert(int data);
    Node* insertRecursive(Node* root, int data);

    void preorder();
    void preorderRecursive(Node* root);
    void inorder();
    void inorderRecursive(Node* root);
    void postorder();
    void postorderRecursive(Node* root);
    void levelByLevelRecursive(Node* root, int level);
    void levelByLevel();
    void visit(int parameter);

    int height(Node* node);
    void ancestors(int data);
    void ancestorsRecursive(Node* root, int data);
    int whatlevelamI(int data);
    int whatlevelamIRecursive(Node* root, int data, int level);
    bool isEmpty();
    bool isInTree(int data);

    void printOrderedVector();
    

};

int compareVector(std::vector <int> vector);