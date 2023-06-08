//
// Created by Frank on 15/12/2021.
//

#ifndef SEMPROJ2_LINKEDLISTNODE_H
#define SEMPROJ2_LINKEDLISTNODE_H

#endif //SEMPROJ2_LINKEDLISTNODE_H
#include "Item.h"
struct LinkedListNode{
    LinkedListNode(Item item, int value, LinkedListNode * previous = nullptr, LinkedListNode * next = nullptr);
    Item Item;
    int Data;
    LinkedListNode* Previous;
    LinkedListNode* Next;
};