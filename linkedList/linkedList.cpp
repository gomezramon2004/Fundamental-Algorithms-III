#include "linkedList.hpp"

Node::Node(int data) : data(data), next(nullptr) {}

LinkedList::LinkedList() : head(nullptr) {}

void LinkedList::insertNode(int data) {
    if (!head) {
        head = new Node(data);
    } else {
        Node *currentNode = head;
        while (currentNode->next) {
            currentNode = currentNode->next;
        }
        currentNode->next = new Node(data);
    }
}

Node* LinkedList::getHead() {
    return head;
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
