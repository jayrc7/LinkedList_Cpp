//
// Created by Jason Cabrera on 11/19/21.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "../Node/Node.h"

class LinkedList {
    private:
        // fields
        int size;
        Node* head;

    public:
        // constructor
        LinkedList();

        // methods
        Node * addValue(int value);
        Node * removeValue(int value);
        int getIndexValue(int index);
        Node * addIndex(int index, int value);
        Node * removeIndex(int index);
        int getSize();
        void printList();

};


#endif //LINKEDLIST_H
