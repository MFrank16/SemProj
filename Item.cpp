//
// Created by Frank on 15/12/2021.
//

#include "Item.h"

Item::Item(char look, std::string &&name, char type, int price)
    :Look(look), Name(move(name)), Type(type), Price(price)
{
    //Nothing here...
}

Item::~Item() {
}


