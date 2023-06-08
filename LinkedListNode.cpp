//
// Created by Frank on 15/12/2021.
//

#include "LinkedListNode.h"

#include <utility>

LinkedListNode::LinkedListNode(class Item item, int value, LinkedListNode *previous, LinkedListNode *next)
        : Item(std::move(item)), Data(value), Previous(previous), Next(next)
{
    //Nothing here...
}


