//
// Created by Frank on 15/12/2021.
//

#include "Automat.h"
#include <windows.h>


Automat::Automat(int width, int height, int depth, std::string code, std::string classification, int maxCoins)
        :Width(width), Height(height), Depth(depth), Code(move(code)), Classification(move(classification))
{
    int Num_of_rows = width * height * depth;
    try{
        if (width <= 0 || height <= 0 || depth <= 0 || Num_of_rows > MAX_SIZE){
            //return;
            throw (Exception("Wrong Size"));
        }
    }
    catch(Exception& e){
        Width = 1;
        Height = 1;
        Depth = 1;
    }
    initializeMags(maxCoins);
    initializeRows();
}

bool Automat::initializeRows() {

    for (int i = 0; i < Width * Height; i++){
        LinkedList *s1 = new LinkedList();
        My_Rows.push_back(*s1);
    }
    return true;
}

Automat::~Automat() {
    if(My_Rows.empty()){
        return;
    }
    else{
        My_Rows.clear();
        return;
    }
}

std::string Automat::getSize() {
    std::ostringstream output;
    output << Width << ":" << Height << ":" << Depth;
    return output.str();
}

int Automat::getRows() {
    std::vector<LinkedList>::iterator it;
    int i = 0;
    for (it = My_Rows.begin(); it != My_Rows.end(); ++it){
        i++;
    }
    return i;
}

bool Automat::putItem(Item item, int row) {
    if (row > (Width * Height)){
        return false;
    }
    int value = 1;
    int iterator = 1;
    for (auto it = begin (My_Rows); it != end (My_Rows); ++it) {
        if(iterator == row){
            if(it->getDepth() < Depth){
                it->PushBack(item, value);
                return true;
            }
            else{
                return false;
            }
        }
        iterator++;
    }
}

Item Automat::getFirst(int row) {
    int iterator = 1;
    try {
        if(row > Width * Height){ throw "Wrong row number!";}
        for (auto it = begin(My_Rows); it != end(My_Rows); ++it) {
            if (iterator == row) {
                if(it->getDepth() != 0){
                    Item item = it->getHead().Item;
                    std::cout << item.getname();
                    return item;
                }
            }
            iterator++;
        }
        throw "No item in the row!";
    }
    catch(const char* msg){
        std::cerr << msg << std::endl;
    }
}

Item Automat::getItem(int row, int depth) {
    try{
        if (depth > Depth){ throw "Wrong depth!";}
        int iterator = 1;
        int iterator2 = 1;
        for (auto it = begin(My_Rows); it != end(My_Rows); ++it) {
            if (iterator == row) {
                LinkedListNode tmp(it->getHead());
                while(tmp.Data != 0){
                    if(iterator2 == depth){
                        Item item = tmp.Item;
                        std::cout << item.getname();
                        return item;
                    }
                    tmp = *tmp.Next;
                    iterator2++;
                }
            }
            iterator++;
        }
    }
    catch(const char* msg){
        std::cerr << msg << std::endl;
    }
}

bool Automat::depositCoin(Coin coin) {
    try {
        if (!cmpf(coin.getValue(), 0.10) && !cmpf(coin.getValue(), 0.20) && !cmpf(coin.getValue(), 0.50) &&
            !cmpf(coin.getValue(), 1) && !cmpf(coin.getValue(), 2)) {
            throw "Unrecognised coin!";
        }
        for (auto it = begin(Zasobniky); it != end(Zasobniky); ++it) {
            if(it->getType() == coin.getValue()){
                if(it->getCurr() < it->getMax()){
                    it->pushBack(coin);
                    addBalance(coin.getValue());
                    return true;
                }
                else{
                    throw "Not enough space for coin!";
                }
            }
        }
    }
        catch(const char* msg){
            std::cerr << msg << std::endl;
        }
}

bool Automat::cmpf(float A, float B, float epsilon) {
    return (fabs(A - B) < epsilon);
}

bool Automat::initializeMags(int maxCoins) {
    float type;
    for (int i = 1; i <= 6; i++){
        switch(i){
            case 1:
                type = 0.10;
                break;
            case 2:
                type = 0.20;
                break;
            case 3:
                type = 0.50;
                break;
            case 4:
                type = 1;
                break;
            case 5:
                type = 2;
                break;
            case 6:
                type = 420;
                break;
        }
        Magazine *s1 = new Magazine(type, maxCoins);
        Zasobniky.push_back(*s1);
    }
}

bool Automat::depositCoin(float value) {
    try {
        if (!cmpf(value, 0.10) && !cmpf(value, 0.20) && !cmpf(value, 0.50) &&
            !cmpf(value, 1) && !cmpf(value, 2)) {
            throw "Unrecognised coin!";
        }
        for (auto it = begin(Zasobniky); it != end(Zasobniky); ++it) {
            if(it->getType() == value){
                if(it->getCurr() < it->getMax()){
                    Coin *coin = new Coin(value);
                    it->pushBack(*coin);
                    addBalance(value);
                    return true;
                }
                else{
                    throw "Not enough space for coin!";
                }
            }
        }
    }
    catch(const char* msg){
        std::cerr << msg << std::endl;
        return false;
    }
}

bool Automat::addBalance(float value) {
    if (value < 0){ return false; }
    customerMoney += value;
    SetConsoleOutputCP(1252);
    return true;
//    std::cout << customerMoney << (char)(128) << "\n";
}

bool Automat::sellProduct(int row) {
    try {
        if(getAmountOfCoins(2) < 2 || getAmountOfCoins(1) < 3 || getAmountOfCoins(0.50) < 7 || getAmountOfCoins(0.20) < 8 || getAmountOfCoins(0.10) < 12){
            throw "We are sorry, but the machine is out of change. Please try again later.";
        }
        float price = getFirst(row).getprice();
        if (customerMoney >= price) {
            customerMoney -= price;
            dropSelected(row);
            GiveChange();
            return true;
        } else {
            throw "Not enough money!";
        }
    }
    catch(const char* msg){
        std::cerr << msg << std::endl;
        return false;
    }
}

bool Automat::dropSelected(int row) {
    int iterator = 1;
    bool yes = false;
    for (auto it = begin(My_Rows); it != end(My_Rows); ++it) {
        if(iterator == row){
            yes = it->RemoveFirst();
            return yes;
        }
        iterator++;
    }
    return yes;
}

std::vector<Coin> Automat::GiveChange() {
    std::vector<Coin> change;
    int two = 0;
    int one = 0;
    int fifty = 0;
    int twenty = 0;
    int ten = 0;
    while (customerMoney > 0){
        if(customerMoney >= 2 && getAmountOfCoins(2) > two){
            two++;
            customerMoney -= 2;
        }
        else if(customerMoney >= 1 && getAmountOfCoins(1) > two){
            one++;
            customerMoney -= 1;
        }
        else if(customerMoney >= 0.50 && getAmountOfCoins(0.50) > two){
            fifty++;
            customerMoney -= 0.50;
        }
        else if(customerMoney >= 0.20 && getAmountOfCoins(0.20) > two){
            twenty++;
            customerMoney -= 0.20;
        }
        else if(customerMoney >= 0.10 && getAmountOfCoins(0.10) > two){
            ten++;
            customerMoney -= 0.10;
        }
    }
    for(int i = 0; i < two; i++){
        Coin *minca = new Coin(2);
        change.push_back(*minca);
    }
    for(int i = 0; i < one; i++){
        Coin *minca = new Coin(1);
        change.push_back(*minca);
    }
    for(int i = 0; i < fifty; i++){
        Coin *minca = new Coin(0.50);
        change.push_back(*minca);
    }
    for(int i = 0; i < twenty; i++){
        Coin *minca = new Coin(0.20);
        change.push_back(*minca);
    }
    for(int i = 0; i < ten; i++){
        Coin *minca = new Coin(0.10);
        change.push_back(*minca);
    }
    return change;

}

int Automat::getAmountOfCoins(float type) {
    for (auto it = begin(Zasobniky); it != end(Zasobniky); ++it) {
       if(type == it->getType()){
           return it->getCurr();
       }
    }
}

void Automat::restockChange() {
    for(int i = 0; i < 10; i++) {
        depositCoin(2);
    }
    for(int i = 0; i < 10; i++) {
        depositCoin(1);
    }
    for(int i = 0; i < 12; i++) {
        depositCoin(0.50);
    }
    for(int i = 0; i < 20; i++) {
        depositCoin(0.20);
    }
    for(int i = 0; i < 25; i++) {
        depositCoin(0.10);
    }
    clearCustomerMoney();
}

void Automat::restockProducts() {
    for (auto it = begin(My_Rows); it != end(My_Rows); ++it) {
        for(int i = 0; i < Depth; i++){
            Item *item = new Item('P', "koka-kola", 'p', 1);
            it->PushBack(*item, 1);
        }
    }
}

int Automat::getAmountOfItems() {
    int total = 0;
    for (auto it = begin(My_Rows); it != end(My_Rows); ++it) {
        total += it->getDepth();
    }
    return total;
}










