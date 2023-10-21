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
        Node* getHead();
        void insertNode(int data);
        void printList();
        void clear();
};