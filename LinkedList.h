//
// Created by Frank on 15/12/2021.
//

#ifndef SEMPROJ2_LINKEDLIST_H
#define SEMPROJ2_LINKEDLIST_H

#endif //SEMPROJ2_LINKEDLIST_H
#include "LinkedListNode.h"
#include <iostream>
class LinkedList{
public:

    LinkedList();
    ~LinkedList();

    void PushBack(Item item, int value);
    bool RemoveFirst();
    int getDepth() const { return Depth; }
    LinkedListNode getHead() const { return *Head;}
    friend std::ostream& operator <<(std::ostream& ostr, const LinkedList& rhs);
private:
    LinkedListNode* Head;
    int Depth = 0;

};