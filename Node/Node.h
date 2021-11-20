//
// Created by Jason Cabrera on 11/19/21.
//

#ifndef LINKEDLIST_NODE_H
#define LINKEDLIST_NODE_H


class Node {
    public:
        // fields
        Node* next;
        int value;

        // constructors
        Node();
        explicit Node(int value);
};


#endif //LINKEDLIST_NODE_H
