#include "linkedList.hpp"
#include <iostream>

Node::Node(int data) : data(data), next(nullptr) {}

LinkedList::LinkedList() : head(nullptr) {}

Node* LinkedList::getHead() {
    return head;
}

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

void LinkedList::printList() {
    Node *currentNode = head;
    while (currentNode) {
        std::cout << currentNode->data << " ";
        currentNode = currentNode->next;
    }
    std::cout << std::endl;
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
