#pragma once
#include <vector>
#include "../linkedList/linkedList.hpp"

class NodeBST {
    public:
        int data;
        int level;
        NodeBST *left;
        NodeBST *right;
        NodeBST *prev;
        NodeBST(int data);
};

class BST {
    private:
        int currentLength;
        int currentHeight;
        LinkedList comparisonList;
        NodeBST* root;
        void compareNodes(NodeBST* currentNodeBST, NodeBST* newNodeBST);
        NodeBST* searchNode(int data, NodeBST* currentNodeBST, bool isLevel);
        void deleteLeaftNode(NodeBST* currentNodeBST);
        void deleteNodeWithLeftChild(NodeBST* currentNodeBST);
        void deleteNodeWithRightChild(NodeBST* currentNodeBST);
        void deleteNodeWithTwoChildren(NodeBST* currentNodeBST);
        NodeBST* minRight(NodeBST* currentNodeBST);
        int calculateHeight(NodeBST* currentNodeBST);
        void preorder(NodeBST* currentNodeBST);
        void inorder(NodeBST* currentNodeBST);
        void postorder(NodeBST* currentNodeBST);
        void levelByLevel(NodeBST* currentNodeBST);
    public:
        BST();
        void insertNode(int data);
        void deleteNode(int data);
        bool search(int data);
        int top(); 
        bool empty();
        int size();
        void visit(int key);
        int height();
        void ancestors(int data);
        int whatlevelamI(int data);
        LinkedList getComparisonList();
};

int compare(Node* head);