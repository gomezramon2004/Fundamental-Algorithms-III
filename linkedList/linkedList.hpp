#pragma once

class Node {
    public:
        int data;
        Node *next;
        Node(int data);
};

class LinkedList {
    private:
        Node *head;
    public:
        LinkedList();
        void insertNode(int data);
        Node* getHead();
        void clear();
};