//
// Created by Jason Cabrera on 11/19/21.
//

#include "Node.h"
Node::Node() {
    value = -1;
    next = nullptr;
}

Node::Node(int value) {
    this->value = value;
    next = nullptr;
}

