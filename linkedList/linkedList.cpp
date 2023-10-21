#include "linkedList.hpp"

Node::Node(int data) : data(data), next(nullptr) {}

LinkedList::LinkedList() : head(nullptr) {}

void LinkedList::insertNode(int data) {
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void LinkedList::clear() {
    Node *currentNode = head;
    while (currentNode) {
        Node *temp = currentNode;
        currentNode = currentNode->next;
        delete temp;
    }
    head = nullptr;
}
