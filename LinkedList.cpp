//
// Created by Frank on 15/12/2021.
//
#include "LinkedList.h"

LinkedList::LinkedList()                //Defaultny konstruktor
        :Head(nullptr)
{
    //Nothing Here...
}

LinkedList::~LinkedList() {

}

void LinkedList::PushBack(Item item, int value) {
    if(Head == nullptr){            //Empty case
        Head = new LinkedListNode(item, value);
    }
    else{                           //Non Empty case
        LinkedListNode * Current = Head;
        while(Current -> Next != nullptr){
            Current = Current -> Next;
        }
        LinkedListNode * Temp = new LinkedListNode(item, value, Current);
        Current->Next = Temp;
    }
    Depth++;
}

std::ostream &operator<<(std::ostream &ostr, const LinkedList &rhs) {
    std::cout << "---------------------" << "\n";
    LinkedListNode* Current = rhs.Head;
    while (Current != nullptr){
        std::cout << Current->Data << "," << Current->Item.getname() << " --> ";
        Current = Current->Next;
    }
    if (Current == nullptr){ std::cout << "end";}
    std::cout << "\n---------------------" << "\n";
    return ostr;

}

bool LinkedList::RemoveFirst() {
    if(Head == nullptr){
        return false;
    }
    LinkedListNode* temp = Head;
    Head = Head->Next;
    Depth--;
    free(temp);
    return true;
}



