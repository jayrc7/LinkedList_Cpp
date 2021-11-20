#include <iostream>
#include "LinkedList/LinkedList.h"

int main() {
    LinkedList* list = new LinkedList();
    list->addValue(4);
    list->addValue(2);
    list->addValue(3);
    list->addValue(6);

    std::cout << "Adding elements to list..." << std::endl;
    list->printList();
    assert(list->getSize() == 4);

    Node* removedNode = list->removeValue(3);
    std::cout << "Removing 3 from list..." << std::endl;
    list->printList();
    assert(removedNode->value == 3);
    assert(list->getSize() == 3);

    std::cout << "Getting value of node at index 1..." << std::endl;
    int value = list->getIndexValue(1);
    std::cout << value << std::endl;
    assert(value == 2);
    assert(list->getSize() == 3);

    std::cout << "Adding 7 to list at index 2..." << std::endl;
    list->addIndex(7, 2);
    list->printList();
    assert(list->getSize() == 4);

    std::cout << "Adding 5 to list at index 0..." << std::endl;
    list->addIndex(5, 0);
    list->printList();
    assert(list->getSize() == 5);

    std::cout << "Removing index 0..." << std::endl;
    list->removeIndex(0);
    list->printList();
    assert(list->getSize() == 4);

    std::cout << "Removing index 2..." << std::endl;
    list->removeIndex(2);
    list->printList();
    assert(list->getSize() == 3);

    std::cout << std::endl << "All tests passed." << std::endl;
    return 0;
}
