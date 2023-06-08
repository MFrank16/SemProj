//
// Created by Frank on 15/12/2021.
//

#ifndef SEMPROJ2_ITEM_H
#define SEMPROJ2_ITEM_H

#endif //SEMPROJ2_ITEM_H
#include <iostream>

class Item{
public:
    Item(char look = 'O', std::string &&name = "Undefined", char type = 'e', int price = 0);    //konstruktor
    ~Item();
    std::string getname(){return Name;}
    char gettype(){return Type;}
    int getprice(){return Price;}
private:
    char Look = 'O';
    std::string Name = "Undefined";
    char Type = 'e';
    int Price;
};