//
// Created by Jason Cabrera on 11/19/21.
//

#include <stdexcept>
#include <iostream>
#include "LinkedList.h"

LinkedList::LinkedList() {
    size = 0;
    head = new Node();
}

Node* LinkedList::addValue(int value) {
    Node* currentNode = head;

    // iterate through linked list until reaching the end (nullptr)
    while (currentNode != nullptr && currentNode->next != nullptr) {
        if (currentNode->value == value) throw std::runtime_error("Value already exists in list.");
        currentNode = currentNode->next;
    }

    // replace nullptr at end of list with new node
    currentNode->next = new Node(value);
    size++;

    return currentNode->next;
}

Node* LinkedList::removeValue(int value) {
    // error check for empty list
    if (size == 0) throw std::runtime_error("Node is empty.");

    // define currentNode at beginning of linked list
    Node* currentNode = head;

    // iterate over list, find node who's next node contains the value being searched for
    while (currentNode != nullptr && currentNode->next != nullptr && currentNode->next->value != value)
        currentNode = currentNode->next;

    // return nullptr if node containing value was not found
    if (currentNode == nullptr) throw std::runtime_error("Node not found.");

    // remove node containing value being searched for
    Node* removedNode = currentNode->next;
    currentNode->next = currentNode->next->next;
    size--;

    return removedNode;
}

int LinkedList::getIndexValue(int index) {
    // error check for empty linked list and index out of bounds
    if (size == 0) throw std::runtime_error("Linked list is empty.");
    if (index >= size) throw std::runtime_error("Index out of bounds.");

    // instantiate fields to iterate over linked list
    int currentIdx = 0;
    Node* currentNode = head->next;

    // iterate until current index is desired index
    while (currentIdx != index) {
        currentNode = currentNode->next;
        currentIdx++;
    }

    // return value of desired index
    return currentNode->value;
}

Node* LinkedList::addIndex(int value, int index) {
    // error check for index out of bounds
    if (index >= size) throw std::runtime_error("Index out of bounds.");

    // iterate over list until node with index-1 is reached
    Node* currentNode = head;
    int currentIndex = -1;
    while (currentNode != nullptr && currentIndex != index-1) {
        currentNode = currentNode->next;
        currentIndex++;
    }

    // add new node between current node and rest of linked list
    Node* temp = currentNode->next;
    currentNode->next = new Node(value);
    currentNode->next->next = temp;
    size++;

    return currentNode->next;
}

Node* LinkedList::removeIndex(int index) {
    // error check for empty linked list and index out of bounds
    if (size == 0) throw std::runtime_error("Linked list is empty.");
    if (index >= size) throw std::runtime_error("Index out of bounds.");

    // iterate over list until node with index-1 is reached
    Node* currentNode = head;
    int currentIndex = -1;
    while (currentNode != nullptr && currentIndex != index-1) {
        currentNode = currentNode->next;
        currentIndex++;
    }

    // add new node between current node and rest of linked list
    Node* removedNode = currentNode->next;
    currentNode->next = currentNode->next->next;
    size--;

    return removedNode;
}

int LinkedList::getSize() {
    return size;
}

void LinkedList::printList() {
    // print node value while iterating over list
    std::cout << "List:";
    Node* currentNode = head->next;
    while (currentNode != nullptr) {
        std::cout << " " << currentNode->value;
        currentNode = currentNode->next;
    }
    std::cout << std::endl;
}

